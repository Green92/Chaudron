#ifndef ABSTRACT_RENDERER_HPP
#define ABSTRACT_RENDERER_HPP

#include "../control/constants.hpp"

class AbstractRenderer {

	private:
		VideoBuffer m_vbufs[MAX_CUBES];
		unsigned char nbCubes = 0;

		inline VideoBuffer *getVideoBuffer(unsigned char cubeID) {
			return m_vbufs + cubeID;
		}

	protected:
		virtual Sifteo::VideoMode getVideoMode() const;
		virtual void renderCube(unsigned char id, Sifteo::VideoBuffer *buffer);

	public:
		AbstractRenderer() {

		}

		void registerCube(unsigned char cubeId) {
			m_vbufs[cubeId].initMode(getVideoMode());
			m_vbufs[cubeId].attach(cubeId);
			nbCubes++;
		}

		void updateCube(unsigned char cubeId) {
			VideoBuffer *vBuf = getVideoBuffer(cubeId);
			renderCube(cubeId, vBuf);
		}

		void updateAll() {
			for (unsigned char i = 0; i < nbCubes; i++) {
				updateCube(i);
			}
		}
};

#endif