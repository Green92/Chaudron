#ifndef GAME_MODEL_HPP
#define GAME_MODEL_HPP

#include <sifteo/array.h>
#include <sifteo/time.h>
#include <sifteo/math.h>

#include "../control/constants.hpp"

#include "request.hpp"

class GameModel {
	
	private:
		Role cubeRoles[MAX_CUBES];

		Request *currentRequest = NULL;
		int score = 0;

	public:
		GameModel() {
			for (unsigned char i=0; i<MAX_CUBES; i++) {
				cubeRoles[i] = Roles::getInitialRole(i);
			}
		}

		inline Role getCubeRole(unsigned char id) const {
			return cubeRoles[id];
		}

		inline void setCubeRole(unsigned char id, Role role) {
			cubeRoles[id] = role;
		}

		inline void resetCubeRole(unsigned char id) {
			cubeRoles[id] = Roles::getInitialRole(id);
		}

		inline void increaseScore(unsigned value) {
			score += value;
		}

		inline void decreaseScore(unsigned value) {
			score -= value;
		}

		inline int getScore() const {
			return score;
		}

		inline void setCurrentRequest(Request *request) {
			currentRequest = request;
		}

		inline Request *getCurrentRequest() const {
			return currentRequest;
		}
};

#endif