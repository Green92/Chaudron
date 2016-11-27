#ifndef STATE_HPP
#define STATE_HPP

class Game;

class State {

	private:
		Game *game;

	protected:
		Sifteo::VideoBuffer *vBuf;

		void runState(State *state, void *dataPtr = NULL);

	public:
		State(Game *game, Sifteo::VideoBuffer *vBuf) {
			this->game = game;
			this->vBuf = vBuf;
		}

		void start(void *dataPtr) {
			for (Sifteo::CubeID cube : Sifteo::CubeSet::connected()) {
	            onCubeConnected(cube);
	        }

	        onStateStart(dataPtr);
		}


		virtual void updateState(Sifteo::TimeDelta deltaTime) {

		}

		virtual void onStateStart(void *dataPtr) {

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