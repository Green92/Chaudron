#ifndef TEXT_RENDERER_HPP
#define TEXT_RENDERER_HPP

#include "abstract_renderer.hpp"

class TextRenderer : public AbstractRenderer {

	private:
		const char *textFromRole(Role role) {
			switch (role) {
				case VILLAGE: 	return "Village";
				case WATER:		return "Water";
				case FIRE:		return "Fire";
				case LIFE:		return "Life";
				case GROUND:	return "Ground";
				case EMPTY:		return "Empty";
				case STEAM:		return "Steam";
				case FIELD:		return "Field";
			}

			return "Error";
		}

	protected:
		Sifteo::VideoMode getVideoMode() const {
			return BG0_ROM;
		}

		void render(unsigned char cubeId, VideoBuffer *videoBuffer, Role role) {
			videoBuffer->bg0rom.erase();
			videoBuffer->bg0rom.text(vec(1, 1), textFromRole(role));
		}
};

#endif