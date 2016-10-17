#ifndef WATER_ROLE_HPP
#define WATER_ROLE_HPP

#include "../role.hpp"

class WaterRole : Role {
	virtual const char * getName() const {
		return "water";
	}
};

#endif