#ifndef LIFE_ROLE_HPP
#define LIFE_ROLE_HPP

#include "../role.hpp"

class LifeRole : Role {
	virtual const char * getName() const {
		return "life";
	}
};

#endif