#ifndef ABSTRACT_RENDERER_HPP
#define ABSTRACT_RENDERER_HPP

#define MAX_CUBES 12

class AbstractRenderer {

	private:
		VideoBuffer m_vbufs[MAX_CUBES];
		unsigned char nbCubes = 0;

		VideoBuffer *getVideoBuffer(unsigned char cubeID) {
			return m_vbufs + cubeID;
		}

	protected:
		virtual Sifteo::VideoMode getVideoMode() const;
		virtual void render(unsigned char cubeId, VideoBuffer *videoBuffer, Role role);

	public:
		void registerCube(unsigned char cubeId) {
			m_vbufs[cubeId].initMode(getVideoMode());
			m_vbufs[cubeId].attach(cubeId);
			nbCubes++;
		}

		void update(Role *roles) {
			for (unsigned char i = 0; i < nbCubes; i++) {
				render(i, getVideoBuffer(i), roles[i]);
			}
		}
};

#endif