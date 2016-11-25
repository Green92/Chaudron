#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <sifteo/math.h>

#include "constants.hpp"

#define MILLIS_IN_A_SECOND 1000

class Level {
	protected:
		GameState *gameState;
		AbstractRenderer *renderer;
		Random rng;
		Sifteo::Array<Role, ROLE_NUMBER * 2, unsigned char> roles;
		unsigned needInterval;
		unsigned maxLevel;
};

#endif