#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <sifteo/array.h>
#include <sifteo/time.h>
#include <sifteo/math.h>

#include "../control/constants.hpp"

//These values are in second
#define NEXT_NEED_MIN 14
#define NEXT_NEED_MAX 15

class VillageState {

	private:
		Sifteo::Array<Role, MAX_NEEDS, unsigned char> needs;

	public:
		int nextNeed;
		bool addNeed(Role role) {
			if (needs.count() == MAX_NEEDS) {
				return false;
			}

			needs.push_back(role);
			return true;
		}

		bool removeNeed(Role role) {
			unsigned roleIndex = needs.find(role);

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
		CAULDRON, 	DEBUG_MINUS,
		DEBUG_PLUS, MANDRAGORA,
		INSECTS, 	EYES,
		MUSHROOMS, 	MANDRAGORA,
		INSECTS, 	EYES,
		MUSHROOMS, 	MANDRAGORA
	};

	unsigned char HUDIndex = 0;

	VillageState villageState;

} GameState;

#endif