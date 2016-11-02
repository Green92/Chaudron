#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "../control/constants.hpp"

typedef struct villageState {
	unsigned char uselessfornow;
} VillageState;

typedef struct gameState {
	
	Role cubeRoles[MAX_CUBES] = { 
		VILLAGE, 	HUD,
		FIRE, 		WATER,
		GROUND, 	LIFE,
		EMPTY, 		EMPTY,
		EMPTY, 		EMPTY,
		EMPTY, 		EMPTY
	};

	unsigned char HUDIndex = 0;

	VillageState villageState;

} GameState;

#endif