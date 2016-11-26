#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <sifteo/array.h>
#include <sifteo/time.h>
#include <sifteo/math.h>

#include "../control/constants.hpp"

//These values are in second
#define NEXT_NEED_MIN 14
#define NEXT_NEED_MAX 15

#include "request.hpp"

struct VillageState {
		Request *currentRequest = NULL;
		unsigned int score = 0;
};

typedef struct gameState {
	
	Role cubeRoles[MAX_CUBES] = { 
		CAULDRON,
		MANDRAGORA, INSECTS, 	
		EYES,		MUSHROOMS,
		MANDRAGORA, INSECTS, 	
		EYES,		MUSHROOMS
	};

	unsigned char HUDIndex = 0;

	VillageState villageState;

} GameState;

#endif