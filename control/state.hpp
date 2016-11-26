#ifndef STATE_HPP
#define STATE_HPP

class Game;

class State {

	private:
		Game *game;

	protected:
		void runState(State *state);

	public:
		State(Game *game) {
			this->game = game;
		}

		void start() {
			for (Sifteo::CubeID cube : Sifteo::CubeSet::connected()) {
	            onCubeConnected(cube);
	        }

	        onStateStart();
		}


		virtual void updateState(Sifteo::TimeDelta deltaTime) {

		}

		virtual void onStateStart() {

		}

		virtual void onCubeConnected(unsigned id) {

		}

		virtual void onNeighborAdd(unsigned firstID, unsigned secondID) {

		}

		virtual void onNeighborRemove(unsigned firstID, unsigned secondID) {

		}

		virtual void onCubeAccelChange(unsigned id) {

		}

		virtual void onCubeTouch(unsigned id) {

		}
};

#endif