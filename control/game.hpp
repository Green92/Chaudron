#include <sifteo.h>

#include "../model/associations.hpp"
#include "../view/text_renderer.hpp"

#define MIN_CUBES 9
#define MAX_CUBES 12

using namespace Sifteo;

class Game {

	private:
		Role roles[MAX_CUBES] = { 
			VILLAGE, FIRE,
			GROUND, LIFE,
			WATER, EMPTY,
			EMPTY, EMPTY,
			EMPTY, EMPTY,
			EMPTY, EMPTY
		};

		TextRenderer renderer;

		void onConnect(unsigned id) {
			LOG("Cube connected: %d\n", id);

			renderer.registerCube(id);
			renderer.updateCube(id, roles);		
		}

		void onNeighborRemove(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide)
	    {
	        LOG("Neighbor remove: %02x:%d - %02x:%d\n", firstID, firstSide, secondID, secondSide);
	    }

	    void onNeighborAdd(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide)
	    {
	        LOG("Neighbor add: %02x:%d - %02x:%d\n", firstID, firstSide, secondID, secondSide);

	        const Association *assoc = Associations::search(roles[firstID], roles[secondID]);

	        if (assoc != NULL) {
	        	roles[firstID] = assoc->getResult1();
	        	roles[secondID] = assoc->getResult2();
	        	renderer.updateAll(roles);
	        }
	    }

	    void listenEvents() {
	    	Events::neighborAdd.set(&Game::onNeighborAdd, this);
        	Events::neighborRemove.set(&Game::onNeighborRemove, this);
        	Events::cubeConnect.set(&Game::onConnect, this);

        	// Handle already-connected cubes
	        for (CubeID cube : CubeSet::connected())
	            onConnect(cube);
	    }

	public:
		unsigned run() {
			listenEvents();

			System::setCubeRange(MIN_CUBES, MAX_CUBES);

			// We're entirely event-driven. Everything is
		    // updated by SensorListener's event callbacks.
		    TimeStep ts;
		    while (true)
		    {
		        System::paint();
		        ts.next();
		    }

		    return 0;
		}

};