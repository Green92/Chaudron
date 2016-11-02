#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <sifteo/array.h>
#include <sifteo/time.h>
#include <sifteo/math.h>

#include "../control/constants.hpp"

//These values are in second
#define NEXT_NEED_MIN 1
#define NEXT_NEED_MAX 5

class VillageState {

	private:
		Sifteo::Array<Role, MAX_NEEDS, unsigned char> needs;

	public:
		bool addNeed(Role role) {
			if (needs.count() == MAX_NEEDS) {
				return false;
			}

			needs.push_back(role);
			return true;
		}

		bool removeNeed(Role role) {
			unsigned roleIndex = needs.find(role);
			for (int i=0; i<needs.count(); i++) 
				LOG("%d %d %d\n", roleIndex, role, needs[i]);
			if (roleIndex != needs.NOT_FOUND) {
				needs.erase(roleIndex);
				return true;
			}

			return false;
		}

		const Sifteo::Array<Role, MAX_NEEDS, unsigned char> &getNeeds() const {
			return needs;
		}
};

typedef struct gameState {
	
	Role cubeRoles[MAX_CUBES] = { 
		VILLAGE, 	WATER,
		GROUND, 	FIRE,
		TOOLS, 		WATER,
		GROUND, 	FIRE,
		TOOLS, 		WATER,
		GROUND, 	FIRE
	};

	unsigned char HUDIndex = 0;

	VillageState villageState;

} GameState;

#endif