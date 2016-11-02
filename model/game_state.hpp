#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <sifteo/array.h>
#include <sifteo/time.h>
#include <sifteo/math.h>

#include "../control/constants.hpp"
#include "../control/constants.hpp"

//These values are in second
#define NEXT_NEED_MIN 5
#define NEXT_NEED_MAX 10

class VillageState {

	private:
		Sifteo::Array<Role, MAX_NEEDS, unsigned char> needs;

		Sifteo::Array<Role, ROLE_NUMBER * 3, unsigned char> roles;

		int32_t nextNeed = 0;
		Sifteo::Random rng;

		bool addNeed(Role role) {
			if (needs.count() == MAX_NEEDS) {
				return false;
			}

			needs.push_back(role);
			return true;
		}

	public:
		VillageState() {
			for (Role i=VILLAGE; i<ROLE_NUMBER; i++) {
				int chance = Roles::getNeed(i);

				for (int j=0; j<chance; j++) {
					roles.push_back(i);
				}
			}
		}

		bool removeNeed(Role role) {
			Sifteo::Array<Role, MAX_NEEDS, unsigned char>::iterator it;

			for (it=needs.end(); it != needs.begin(); it--) {
				if (*it == role) {
					needs.erase(it);
					return true;
				}
			}

			return false;
		}

		bool live(Sifteo::TimeDelta delta) {
			nextNeed -= delta.milliseconds();
			bool result = true;

			if (nextNeed < 1) {
				nextNeed = rng.randrange(NEXT_NEED_MIN * 1000, NEXT_NEED_MAX * 1000);
				result = addNeed(rng.randrange(0, 3 * ROLE_NUMBER));
			}

			return result;
		}

		const Sifteo::Array<Role, MAX_NEEDS, unsigned char> &getNeeds() const {
			return needs;
		}
};

typedef struct gameState {
	
	Role cubeRoles[MAX_CUBES] = { 
		VILLAGE, 	HUD,
		FIRE, 		WATER,
		GROUND, 	LIFE,
		WATER, 		EMPTY,
		EMPTY, 		EMPTY,
		EMPTY, 		EMPTY
	};

	unsigned char HUDIndex = 0;

	VillageState villageState;

} GameState;

#endif