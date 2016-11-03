#ifndef ASSOCIATIONS_HPP
#define ASSOCIATIONS_HPP

#include "roles.hpp"

static Association assocs[] = {

	Association(GROUND, WATER, WOOD, WATER),
	Association(WATER, FIRE, STEAM, FIRE),
	Association(TOOLS, FIRE, TOOLS, CAMPFIRE),
	Association(TOOLS, WATER, FISHING_BOAT, WATER),
	Association(GROUND, FIRE, BRICKS, FIRE),
	Association(GROUND, TOOLS, GROUND, FIELD),

	Association(FIELD, CAMPFIRE, FOOD, CAMPFIRE),
	Association(FIELD, WOOD, GRAIN_SILO, GROUND),
	Association(CAMPFIRE, BRICKS, OVEN, BRICKS),
	Association(WOOD, FISHING_BOAT, GROUND, LARGE_BOAT),
	Association(BRICKS, FIELD, WINDMILL, FIELD),
	Association(STEAM, BRICKS, WATER, FACTORY),
	Association(STEAM, FISHING_BOAT, FIRE, STEAMBOAT),

	Association(FACTORY, LARGE_BOAT, PORT, LARGE_BOAT),
	Association(WINDMILL, OVEN, GROUND, RESTAURANT),
	Association(FOOD, GRAIN_SILO, GROUND, STORE)

	//Association(WATER, BRICKS, GRAVEYARD, BRICK)

};

//Thank you to increase when adding an association
#define ASSOCIATIONS_NUMBER 17

class Associations {
	public:
		static Association *search(Role item1, Role item2) {
			for (unsigned char i=0; i<ASSOCIATIONS_NUMBER; i++) {
				if (assocs[i].isSame(item1, item2)) {
					return &assocs[i];
				}
			}

			return NULL;
		}

		static Association *getAssociation(unsigned char index) {
			return &assocs[index];
		}
};

#endif