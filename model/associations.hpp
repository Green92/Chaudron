#ifndef ASSOCIATIONS_HPP
#define ASSOCIATIONS_HPP

#include "roles.hpp"

const static Association assocs[] = {
	Association(GROUND, WATER, RICH_GROUND, WATER),
	Association(LIFE, FIRE, GROUND, FIRE),
	Association(LIFE, WATER, COTTON, WATER),
	Association(GROUND, FIRE, CLAY, FIRE),
	Association(GROUND, GROUND, GRAVEYARD, GROUND),

	Association(RICH_GROUND, LIFE, FIELD, LIFE),
	Association(RICH_GROUND, RICH_GROUND, FOREST, RICH_GROUND),
	Association(CLAY, FIRE, BRICK, FIRE),
	Association(RICH_GROUND, FIRE, CLAY, FIRE),

	Association(BRICK, WATER, GRAVEYARD, WATER),
	Association(FIELD, FIRE, GROUND, FIRE),
	Association(WATER, BRICK, WELL, BRICK),
	Association(GRAVEYARD, LIFE, FIELD, LIFE)
};

//Thank you to increase when adding an association
#define ASSOCIATIONS_NUMBER 13

class Associations {
	public:
		static const Association *search(Role item1, Role item2) {
			for (unsigned char i=0; i<ASSOCIATIONS_NUMBER; i++) {
				if (assocs[i].isSame(item1, item2)) {
					return &assocs[i];
				}
			}

			return NULL;
		}

		static const Association *getAssociation(unsigned char index) {
			return &assocs[index];
		}
};

#endif