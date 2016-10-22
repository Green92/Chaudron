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
#define LIFE	5
#define WATER	6

//secondary elements
#define COTTON		7
#define RICH_GROUND	8
#define CLAY		9

//tertiary elements
#define FOREST		10
#define FIELD		11
#define BRICK		12
#define GRAVEYARD	13
#define WELL		14

const static char *roles_names[] = {
	"Village", 
	"HUD", 
	"Empty", 
	"Fire", 
	"Ground", 
	"Life", 
	"Water", 
	"Cotton", 
	"Rich ground", 
	"Clay", 
	"Forest", 
	"Field",
	"Brick", 
	"Graveyard", 
	"Well"
};

class Roles {
	public:
		inline static const char *getRoleName(Role role) {
			return roles_names[role];
		}

		inline static bool isPrimaryElement(Role role) {
			return role >= FIRE && role <= WATER;
		}
};

#endif