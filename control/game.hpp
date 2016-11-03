#include <sifteo.h>

#include "constants.hpp"

#include "../model/associations.hpp"
#include "../view/text_renderer.hpp"

#include "../model/item.hpp"
#include "../model/items.hpp"

#include "level.hpp"

using namespace Sifteo;

class Game {

	private:

		GameState gameState;
		TextRenderer renderer = TextRenderer(&gameState);
		TiltShakeRecognizer motion[MAX_CUBES];
		Level level = Level(&gameState, &renderer);

		void checkAssoc(unsigned firstID, unsigned secondID) {
			const Association *assoc = Associations::search(gameState.cubeRoles[firstID], gameState.cubeRoles[secondID]);

	        if (assoc != NULL) {
    			gameState.cubeRoles[firstID] = assoc->getResult1();
    			gameState.cubeRoles[secondID] = assoc->getResult2();

	        	renderer.updateCube(firstID);
	        	renderer.updateCube(secondID);
	        }
		}

		void checkNeed(unsigned firstID, unsigned secondID) {
			Role role = gameState.cubeRoles[firstID] == VILLAGE ? 
        	gameState.cubeRoles[secondID] : gameState.cubeRoles[firstID];

        	if (gameState.villageState.removeNeed(role)) {
        		renderer.updateCube(0);
        	}
		}

		void onConnect(unsigned id) {
			LOG("Cube connected: %d\n", id);

			renderer.registerCube(id);
			renderer.updateCube(id);

			motion[id].attach(id);
		}

		void onNeighborRemove(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide)
	    {
	        LOG("Neighbor remove: %02x:%d - %02x:%d\n", firstID, firstSide, secondID, secondSide);
	    }

	    void onNeighborAdd(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide)
	    {
	        LOG("Neighbor add: %02x:%d - %02x:%d\n", firstID, firstSide, secondID, secondSide);

	        if (gameState.cubeRoles[firstID] != VILLAGE && gameState.cubeRoles[secondID] != VILLAGE) {
	        	checkAssoc(firstID, secondID);
	        } else {
	        	checkNeed(firstID, secondID);
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
	        			renderer.updateCube(id);
	        		break;

	        		case VILLAGE:
	        		break;

	        		default:
	        			gameState.cubeRoles[id] = Roles::getInitialRole(id);
	        			renderer.updateCube(id);
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

	public:

		unsigned run() {
			listenEvents();

			System::setCubeRange(MIN_CUBES, MAX_CUBES);
			// We're entirely event-driven. Everything is
		    // updated by SensorListener's event callbacks.
		    TimeStep ts;
		    while (level.live(ts.delta()))
		    {
		        System::paint();
		        ts.next();
		    }

		    return 0;
		}

};