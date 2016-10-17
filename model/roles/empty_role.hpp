#ifndef EMPTY_ROLE_HPP
#define EMPTY_ROLE_HPP

#include "../role.hpp"

class EmptyRole : Role {
	virtual const char * getName() const {
		return "empty";
	}
};

#endif
