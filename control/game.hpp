#include <sifteo.h>

#include "constants.hpp"

#include "../model/associations.hpp"
#include "../view/text_renderer.hpp"

using namespace Sifteo;

class Game {

	private:

		int32_t nextNeed = 10000;
		Sifteo::Random rng;

		Sifteo::Array<Role, ROLE_NUMBER * 3, unsigned char> roles;

		GameState gameState;

		TextRenderer renderer;

		TiltShakeRecognizer motion[MAX_CUBES];

		void onConnect(unsigned id) {
			LOG("Cube connected: %d\n", id);

			renderer.registerCube(id);
			renderer.updateCube(id, &gameState);

			motion[id].attach(id);
		}

		void onNeighborRemove(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide)
	    {
	        LOG("Neighbor remove: %02x:%d - %02x:%d\n", firstID, firstSide, secondID, secondSide);
	    }

	    void onNeighborAdd(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide)
	    {
	        LOG("Neighbor add: %02x:%d - %02x:%d\n", firstID, firstSide, secondID, secondSide);

	        if (gameState.cubeRoles[firstID] != CAULDRON && gameState.cubeRoles[secondID] != CAULDRON) {
	        	const Association *assoc = Associations::search(gameState.cubeRoles[firstID], gameState.cubeRoles[secondID]);

		        if (assoc != NULL) {
		        	if (assoc->getResult1() == gameState.cubeRoles[firstID] || assoc->getResult2() == gameState.cubeRoles[secondID]) {
		        		gameState.cubeRoles[firstID] = assoc->getResult1();
		        		gameState.cubeRoles[secondID] = assoc->getResult2();
		        	} else {
		        		gameState.cubeRoles[firstID] = assoc->getResult2();
		        		gameState.cubeRoles[secondID] = assoc->getResult1();
		        	}
		        	
		        	renderer.updateCube(firstID, &gameState);
		        	renderer.updateCube(secondID, &gameState);
		        }
	        } else {
	        	Role role = gameState.cubeRoles[firstID] == CAULDRON ? 
	        		gameState.cubeRoles[secondID] : gameState.cubeRoles[firstID];

	        	if (gameState.villageState.removeNeed(role)) {
	        		renderer.updateCube(0, &gameState);
	        	}
	        }
	    }

	    void onShake(unsigned id) {

	    }

	    void onTilt(unsigned id) {

	    }

        void onAccelChange(unsigned id)
	    {
	        unsigned changeFlags = motion[id].update();
	        if (changeFlags) {
	            // Tilt/shake changed

	            LOG("Tilt/shake changed, flags=%08x\n", changeFlags);

	            //TODO Call onShake or/and onTilt depending of changeFlags
	            //Require to understand the meaning of differents flags...
	        }
	    }

	    void onTouch(unsigned id)
	    {
	        CubeID cube(id);
	        LOG("Touch event on cube #%d, state=%d\n", id, cube.isTouching());

	        if (cube.isTouching()) {
	        	switch (gameState.cubeRoles[id]) {
	        		case HUD:
	        			gameState.HUDIndex = (gameState.HUDIndex + 1) % ASSOCIATIONS_NUMBER;
	        			renderer.updateCube(id, &gameState);
	        		break;

	        		case CAULDRON:
	        		break;

	        		default:
	        			gameState.cubeRoles[id] = Roles::getInitialRole(id);
	        			renderer.updateCube(id, &gameState);
	        		break;
	        	}
	        }
	    }

	    void listenEvents() {
	    	Events::neighborAdd.set(&Game::onNeighborAdd, this);
        	Events::neighborRemove.set(&Game::onNeighborRemove, this);
        	Events::cubeConnect.set(&Game::onConnect, this);
        	Events::cubeAccelChange.set(&Game::onAccelChange, this);
        	Events::cubeTouch.set(&Game::onTouch, this);

        	// Handle already-connected cubes
	        for (CubeID cube : CubeSet::connected()) {
	            onConnect(cube);
	            onAccelChange(cube);
	        }
	    }

	    bool live(Sifteo::TimeDelta delta) {
			nextNeed -= delta.milliseconds();
			bool result = true;

			if (nextNeed < 1) {
				nextNeed = rng.randrange(NEXT_NEED_MIN * 1000, NEXT_NEED_MAX * 1000);
				result = gameState.villageState.addNeed(roles[rng.randrange<unsigned int>(0, roles.count())]);
				renderer.updateCube(0, &gameState);
			}

			return result;
		}

	public:
		unsigned run() {
			listenEvents();

			System::setCubeRange(MIN_CUBES, MAX_CUBES);

			for (Role i=CAULDRON; i<ROLE_NUMBER; i++) {
				int chance = Roles::getNeed(i);

				for (int j=0; j<chance; j++) {
					roles.push_back(i);
				}
			}

			// We're entirely event-driven. Everything is
		    // updated by SensorListener's event callbacks.
		    TimeStep ts;
		    while (live(ts.delta()))
		    {
		        System::paint();
		        ts.next();
		    }

		    return 0;
		}

};