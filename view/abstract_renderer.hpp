#ifndef ABSTRACT_RENDERER_HPP
#define ABSTRACT_RENDERER_HPP

#include "../control/constants.hpp"
#include "../model/game_state.hpp"

class AbstractRenderer {

	private:
		VideoBuffer m_vbufs[MAX_CUBES];
		unsigned char nbCubes = 0;

		inline VideoBuffer *getVideoBuffer(unsigned char cubeID) {
			return m_vbufs + cubeID;
		}

	protected:
		virtual Sifteo::VideoMode getVideoMode() const;
		
		virtual void renderElement(VideoBuffer *videoBuffer, const Role role);
		virtual void renderHUD(VideoBuffer *videoBuffer, const unsigned char HUDIndex);
		virtual void renderVillage(VideoBuffer *videoBuffer, const VillageState &villageState);

	public:
		void registerCube(unsigned char cubeId) {
			m_vbufs[cubeId].initMode(getVideoMode());
			m_vbufs[cubeId].attach(cubeId);
			nbCubes++;
		}

		void updateCube(unsigned char cubeId, const GameState *gameState) {
			
			VideoBuffer *vBuf = getVideoBuffer(cubeId);

			switch (gameState->cubeRoles[cubeId]) {
				default:
					renderElement(vBuf, gameState->cubeRoles[cubeId]);
				break;

				case VILLAGE:
					renderVillage(vBuf, gameState->villageState);
				break;

				case HUD:
					renderHUD(vBuf, gameState->HUDIndex);
				break;
			}
		}

		void updateAll(const GameState *gameState) {
			for (unsigned char i = 0; i < nbCubes; i++) {
				updateCube(i, gameState);
			}
		}
};

#endif