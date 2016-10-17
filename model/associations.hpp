#ifndef ASSOCIATIONS_HPP
#define ASSOCIATIONS_HPP

#include "roles.hpp"

const static Association assocs[] = {
	Association(FIRE, WATER, STEAM, STEAM),
	Association(FIRE, GROUND, LIFE, GROUND),
	Association(GROUND, LIFE, GROUND, FIELD)
};

class Associations {
	public:
		static const Association *search(Role item1, Role item2) {
			for (unsigned char i=0; i<3; i++) {
				if (assocs[i].isSame(item1, item2)) {
					return &assocs[i];
				}
			}

			return NULL;
		}
};

#endif