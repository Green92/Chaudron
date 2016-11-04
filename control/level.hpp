#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <sifteo/math.h>

#include "constants.hpp"

#define MILLIS_IN_A_SECOND 1000

class Level {
	protected:
		GameState *gameState;
		AbstractRenderer *renderer;
		Random rng;
		Sifteo::Array<Role, ROLE_NUMBER * 2, unsigned char> roles;
		unsigned needInterval;
		unsigned maxLevel;

		virtual void initRoles() {
			for (Role i=CAULDRON; i<ROLE_NUMBER; i++) {
				int chance = Roles::getNeed(i);
				
				if (chance >= maxLevel)  {
					for (int j=0; j<chance; j++) {
						roles.push_back(i);
					}
				}
			}
		}
	
	public:
		Level(GameState *gameState, TextRenderer *renderer) {
			this->gameState = gameState;
			this->renderer = renderer;
			rng.seed();
			needInterval = 5;
			gameState->villageState.nextNeed = needInterval * MILLIS_IN_A_SECOND;
			maxLevel = 2;
			initRoles();
		}

		unsigned &needInt() {
			return needInterval;
		}

		unsigned &maxLvl() {
			return maxLevel;
		}

		virtual bool live(Sifteo::TimeDelta delta) {
			gameState->villageState.nextNeed -= delta.milliseconds();
			bool result = true;

			if (gameState->villageState.nextNeed < 1) {
				gameState->villageState.nextNeed = needInterval * MILLIS_IN_A_SECOND;
				result = gameState->villageState.addNeed(roles[rng.randrange<unsigned int>(0, roles.count())]);
			}

			renderer->updateCube(0);

			return result;
		}
};

#endif