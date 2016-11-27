#include <sifteo.h>

#include "constants.hpp"

#include "state.hpp"

using namespace Sifteo;

class Game {

	private:

	protected:
		State *currentState = NULL;

		void onConnect(unsigned id) {
			LOG("Cube connected: %d\n", id);

			currentState->onCubeConnected(id);
		}

		void onNeighborRemove(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide)
	    {
	        LOG("Neighbor remove: %02x:%d - %02x:%d\n", firstID, firstSide, secondID, secondSide);

	        currentState->onNeighborRemove(firstID, secondID);
	    }

	    void onNeighborAdd(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide)
	    {
	        LOG("Neighbor add: %02x:%d - %02x:%d\n", firstID, firstSide, secondID, secondSide);

	        currentState->onNeighborAdd(firstID, secondID);
	    }

	    void onTouch(unsigned id)
	    {
	    	CubeID cube(id);
	        LOG("Touch event on cube #%d, state=%d\n", id, cube.isTouching());

	        currentState->onCubeTouch(id);
	    }

	    void listenEvents() {
	    	LOG("Game : listening events\n");

	    	Events::neighborAdd.set(&Game::onNeighborAdd, this);
        	Events::neighborRemove.set(&Game::onNeighborRemove, this);
        	Events::cubeConnect.set(&Game::onConnect, this);
        	Events::cubeTouch.set(&Game::onTouch, this);
	    }

	public:

		void runState(State *state) {
			this->currentState = state;

			if (state != NULL) {
				state->start();
			}
		}

		unsigned run() {
			LOG("Game : launched\n");

			listenEvents();

			System::setCubeRange(MIN_CUBES, MAX_CUBES);

			// We're entirely event-driven. Everything is
		    // updated by SensorListener's event callbacks.
		    TimeStep ts;
		    while (true)
		    {
		    	if (currentState == NULL) {
					LOG("Game : no state defined : exiting\n");
					return 1;
				}

		    	currentState->updateState(ts.delta());

		        System::paint();
		        ts.next();
		    }

		    return 0;
		}

};

void State::runState(State *state) {
	game->runState(state);
}