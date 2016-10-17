#ifndef CUBE_H
#define CUBE_H

#include "role.hpp"

class Cube {

	private:
		Role *m_role;

	public:
		void setRole(Role *role) {
			m_role = role;
		}
};

# endif