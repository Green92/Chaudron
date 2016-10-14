#ifndef VILLAGE_HPP
#define VILLAGE_HPP

#include "../../assets.gen.h"

#include "../role.hpp"

class Village : Role {
	virtual const char * getName() const {
		return "Village";
	}
};

#endif