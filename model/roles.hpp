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
	"Fishing_boat", 
	"Grain_silo",
	"Oven",
	"Steamboat",
	"Factory",
	"Windmill",
	"Large_boat",
	"Food",
	"Port",
	"Restaurant",
	"Store",
};

const static Role initialRoles[MAX_CUBES] = { 
	VILLAGE, 	WATER,
	GROUND, 	FIRE,
	TOOLS, 		WATER,
	GROUND, 	FIRE,
	TOOLS, 		WATER,
	GROUND, 	FIRE
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
};

#endif