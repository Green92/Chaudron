#ifndef TEXT_RENDERER_HPP
#define TEXT_RENDERER_HPP

#include "abstract_renderer.hpp"

class TextRenderer : public AbstractRenderer {

	private:
		const char *textFromRole(const Role role) const {
			return Roles::getRoleName(role);
		}

	protected:
		Sifteo::VideoMode getVideoMode() const {
			return BG0_ROM;
		}

		void renderHUD(VideoBuffer *videoBuffer) {

		}

		void render(unsigned char cubeId, VideoBuffer *videoBuffer, Role role) {
			videoBuffer->bg0rom.erase();
			videoBuffer->bg0rom.text(vec(1, 1), textFromRole(role));
		}
};

#endif