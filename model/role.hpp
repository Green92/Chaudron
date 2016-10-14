#ifndef ROLE_HPP
#define ROLE_HPP

class Role {

	public:
		virtual const char * getName() const {
			return "undefined role";
		}

		virtual void onCubeConnected(const Role &otherRole) {

		}
};

#endif