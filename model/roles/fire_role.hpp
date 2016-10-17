#ifndef FIRE_ROLE_HPP
#define FIRE_ROLE_HPP

#include "../role.hpp"

class FireRole : Role {
	virtual const char * getName() const {
		return "fire";
	}
};

#endif
