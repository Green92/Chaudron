#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "../control/constants.hpp"

typedef struct villageState {
	unsigned char uselessfornow;
} VillageState;

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