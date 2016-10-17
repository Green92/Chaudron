#ifndef GROUND_ROLE_HPP
#define GROUND_ROLE_HPP

#include "../role.hpp"

class GroundRole : Role {
	virtual const char * getName() const {
		return "ground";
	}
};

#endif