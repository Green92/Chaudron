#ifndef ROLES_HPP
#define ROLES_HPP

#include "role.hpp"
#include "association.hpp"

//Special blocks
#define VILLAGE	0
#define HUD		1

//Empty block
#define EMPTY 	2

//primary elements
#define FIRE	3
#define GROUND 	4
#define TOOLS	5
#define WATER	6

//secondary elements
#define STEAM		 7
#define BRICKS  	 8
#define WOOD		 9
#define FIELD		 10
#define CAMPFIRE     11
#define FISHING_BOAT 12

//tertiary elements
#define GRAIN_SILO	13
#define OVEN		14
#define STEAMBOAT	15
#define FACTORY		16
#define WINDMILL	17
#define LARGE_BOAT	18
#define FOOD		19

//level 4 elements
#define PORT		20
#define RESTAURANT	21
#define STORE		22

#define ROLE_NUMBER 23

const static char *roles_names[] = {
	"Village", 
	"HUD", 
	"Empty", 
	"Fire", 
	"Ground", 
	"Tools", 
	"Water", 
	"Steam", 
	"Bricks", 
	"Wood", 
	"Field",
	"Campfire", 
	"Fishing boat", 
	"Grain silo",
	"Oven",
	"Steamboat",
	"Factory",
	"Windmill",
	"Large boat",
	"Food",
	"Port",
	"Restaurant",
	"Store",
};

const static Role initialRoles[MAX_CUBES] = { 
	VILLAGE, 	HUD,
	GROUND, 	FIRE,
	TOOLS, 		WATER,
	GROUND, 	FIRE,
	TOOLS, 		WATER,
	GROUND, 	FIRE
};

const static unsigned char needs[] = {
		// **Special blocks
	//Special blocks
0, //VILLAGE	0
0, //HUD		0

//Empty block
0, //EMPTY 	2

//primary elements
4, // FIRE	3
4,// GROUND 	4
4,// TOOLS	5
4,// WATER	6

//secondary elements
3, // STEAM		 7
3,// BRICKS  	 8
3, // WOOD		 9
3, // FIELD		 10
3, // CAMPFIRE     11
3, // FISHING_BOAT 12

//tertiary elements
2, // GRAIN_SILO	13
2, // OVEN		14
2, // STEAMBOAT	15
2, // FACTORY		16
2, // WINDMILL	17
2, // LARGE_BOAT	18
2, // FOOD		19

//level 4 elements
1, // PORT		20
1, // RESTAURANT	21
1, // STORE		22

};

class Roles {
	public:
		inline static const char *getRoleName(Role role) {
			return roles_names[role];
		}

		inline static bool isPrimaryElement(Role role) {
			return role >= FIRE && role <= WATER;
		}

		inline static Role getInitialRole(unsigned id) {
			return initialRoles[id];
		}

		inline static Role getNeed(Role need) {
			return needs[need];
		}
};

#endif