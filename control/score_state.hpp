#ifndef SCORE_STATE_HPP
#define SCORE_STATE_HPP

#include "state.hpp"

#include "text_render_util.hpp"
#include "../model/game_model.hpp"

class ScoreState : public State {

	private:
		State *nextState = NULL;

	public:
		ScoreState(Game *game, VideoBuffer *vBuf) :State(game, vBuf) {

		}

		void setNextState(State *state) {
			this->nextState = state;
		}

		void onStateStart(void *dataPtr) {

			GameModel result = *((GameModel *) dataPtr);

			for (CubeID cube=1; cube<MAX_CUBES; ++cube) {
				auto &vid = vBuf[cube];
		        vid.initMode(BG0);
		        vid.attach(cube);
		        vid.bg0.erase(StripeTile);
			}

			auto &vid = vBuf[0];

			vid.initMode(BG0_BG1);
			vid.bg0.erase(StripeTile);
			vid.bg1.erase(StripeTile);
			vid.bg1.eraseMask();

			String<32> str;
			str << "You reach the score of " << result.getScore();

			TextRenderUtil::drawCenteredTextMultiLine(&vid, 6, str.c_str(), 1);
		}

		void onCubeTouch(unsigned id) {
			runState(nextState);
		}
};

#endif