#ifndef PLAY_STATE_HPP
#define PLAY_STATE_HPP

#include "state.hpp"

#include "../model/roles.hpp"
#include "../model/game_model.hpp"
#include "../model/requests.hpp"
#include "../model/associations.hpp"

#include "../view/game_renderer.hpp"

#include "audio_manager.hpp"

#include "state.hpp"

class GameState : public State {
	private:
		GameModel gameModel;
		GameRenderer renderer = GameRenderer(&gameModel);
		AudioManager audioManager;
		Requests requests;

	protected:
		void checkAssoc(unsigned firstID, unsigned secondID) {
			const Association *assoc = Associations::search(gameModel.getCubeRole(firstID), gameModel.getCubeRole(secondID));

	        if (assoc != NULL) {
    			gameModel.setCubeRole(firstID, assoc->getResult1());
    			gameModel.setCubeRole(secondID, assoc->getResult2());

    			audioManager.playSound(CombinaisonValide);

	        	renderer.updateCube(firstID);
	        	renderer.updateCube(secondID);
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

				renderer.updateCube(firstID);
				renderer.updateCube(secondID);

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

				renderer.updateCube(cubeId);
				audioManager.playSound(Reset);
			}
		}

	public:
		GameState(Game *game) :State(game) {

		}

		void onCubeConnected(unsigned id) {
			renderer.registerCube(id);
			renderer.updateCube(id);
		}

		void onStateStart() {
			gameModel.setCurrentRequest(requests.getRandomRequest());

			renderer.updateCube(0);
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

		}
};

#endif