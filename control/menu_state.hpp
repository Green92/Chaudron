#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include <sifteo/menu.h>

#include "state.hpp"

static struct MenuItem menuItems[] = { 
	{&IconPlay, NULL}, 
	{&IconQuit, NULL},
	{NULL, NULL}
};

static struct MenuAssets menuAssets = {
	&StripeTile, //Background tile
	&Footer, //Footer
	&LabelEmpty, //LabelEmpty
	{&Tip0, &Tip1, NULL}
};

class StartMenuState : public State {
	private:
		Sifteo::VideoBuffer vBuf[MAX_CUBES];
		GameState *gameState;
		Menu menu;

	public:
		StartMenuState(Game *game, GameState *gameState) :State(game) {
			this->gameState = gameState;
		}

		void onStateStart() {
			for (CubeID cube=0; cube<MAX_CUBES; ++cube) {
				auto &vid = vBuf[cube];
		        vid.initMode(BG0);
		        vid.attach(cube);
		        vid.bg0.erase(StripeTile);
			}

			menu = Menu(vBuf[0], &menuAssets, menuItems);
		}

		void onCubeTouch(unsigned id) {
			
		}

		void updateState(Sifteo::TimeDelta delta) {
			struct MenuEvent e;

			menu.pollEvent(&e);

			switch (e.type) {
				case MENU_ITEM_PRESS:
					if (e.item == 0) {
						runState(gameState);
					} else {
						runState(NULL);
					}
				break;

				default:
				break;
			}

			menu.performDefault();
		}
};

#endif