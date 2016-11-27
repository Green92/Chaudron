#ifndef PLAY_STATE_HPP
#define PLAY_STATE_HPP

#include "state.hpp"

#include "../model/roles.hpp"
#include "../model/game_model.hpp"
#include "../model/requests.hpp"
#include "../model/associations.hpp"

#include "audio_manager.hpp"
#include "text_render_util.hpp"

#include "state.hpp"

class GameState : public State {
	private:
		GameModel gameModel;
		AudioManager audioManager;
		Requests requests;
		VideoBuffer vBuf[MAX_CUBES];
		int scoreIncrement = -1;

		void checkAssoc(unsigned firstID, unsigned secondID) {
			const Association *assoc = Associations::search(gameModel.getCubeRole(firstID), gameModel.getCubeRole(secondID));

	        if (assoc != NULL) {
    			gameModel.setCubeRole(firstID, assoc->getResult1());
    			gameModel.setCubeRole(secondID, assoc->getResult2());

    			audioManager.playSound(CombinaisonValide);

	        	drawRole(firstID, assoc->getResult1());
	        	drawRole(secondID, assoc->getResult2());
	        } else {
	        	audioManager.playSound(MauvaiseCombinaison);
	        }
		}

		void checkNeed(unsigned firstID, unsigned secondID) {
			unsigned otherId = gameModel.getCubeRole(firstID) != CAULDRON ? 
				firstID : secondID;

			Role role = gameModel.getCubeRole(otherId);

        	const Outcome *outcome = gameModel.getCurrentRequest()->isMatchingOutcome(role);

        	if (outcome != NULL) {
				gameModel.setCurrentRequest(requests.getRandomRequest());
				gameModel.increaseScore(outcome->getGratification());
				gameModel.resetCubeRole(otherId);

				drawRole(otherId, gameModel.getCubeRole(otherId));
				drawRequest(gameModel.getCurrentRequest()->getString());

				audioManager.playSound(BesoinRempli);

				LOG("score : %d\n", gameModel.getScore());
        	} else {
        		audioManager.playSound(MauvaiseCombinaison);
        	}
		}

		void resetItem(unsigned cubeId) {
			Role initialRole = Roles::getInitialRole(cubeId);

			if (gameModel.getCubeRole(cubeId) != initialRole) {
				gameModel.resetCubeRole(cubeId);

				drawRole(cubeId, initialRole);
				audioManager.playSound(Reset);
			}
		}

		void drawRole(unsigned char cubeId, Role role) {
			vBuf[cubeId].bg0.image(vec(0, 0), *Roles::getRoleImage(role));
		}

		void drawRequest(const char *request) {
			vBuf->bg1.eraseMask();
			vBuf->bg1.erase();
			TextRenderUtil::drawCenteredTextMultiLine(vBuf, 6, request, 1);
		}

	public:
		GameState(Game *game) :State(game) {

		}

		void onCubeConnected(unsigned id) {
			vBuf[id].attach(id);
			Role role = gameModel.getCubeRole(id);
			vBuf[id].initMode(role == CAULDRON ? BG0_BG1 : BG0);
			drawRole(id, role);
		}

		void onStateStart() {
			gameModel.setCurrentRequest(requests.getRandomRequest());

			drawRequest(gameModel.getCurrentRequest()->getString());
			audioManager.playMusic(MusiqueLente);
		}

		void onNeighborAdd(unsigned firstID, unsigned secondID) {
			 if (gameModel.getCubeRole(firstID) != CAULDRON &&
			 		gameModel.getCubeRole(secondID) != CAULDRON) {
	        	checkAssoc(firstID, secondID);
	        } else {
	        	checkNeed(firstID, secondID);
	        }
		}

		void onCubeTouch(unsigned id) {
			 CubeID cube(id);

			  if (cube.isTouching()) {
	        	switch (gameModel.getCubeRole(id)) {
	        		case CAULDRON:
	        		break;

	        		default:
	        			resetItem(id);
	        		break;
	        	}
	        }
		}

		void updateState(TimeDelta deltaTime) {
			int score = gameModel.getScore();

			if (scoreIncrement != score) {
				scoreIncrement ++;

				String<4> str;
				str << scoreIncrement;

				TextRenderUtil::drawCenteredTextMonoLine(vBuf, 15, str.c_str());
			}
		}
};

#endif