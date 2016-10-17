#ifndef VILLAGE_ROLE_HPP
#define VILLAGE_ROLE_HPP

#include "../role.hpp"

class VillageRole : Role {
	virtual const char * getName() const {
		return "village";
	}
};

#endif