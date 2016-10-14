#ifndef CUBE_H
#define CUBE_H

#include "role.hpp"

using namespace Sifteo;

class Cube {

	private:
		Role *m_role;

	public:
		void setRole(Role *role) {
			m_role = role;
		}
};

# endif