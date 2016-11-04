#ifndef TEXT_RENDERER_HPP
#define TEXT_RENDERER_HPP

#include "abstract_renderer.hpp"

#include "../model/association.hpp"
#include "../model/associations.hpp"

class TextRenderer : public AbstractRenderer {

	private:
		void renderAssoc(VideoBuffer *videoBuffer, const Association *assoc) {
			videoBuffer->bg0rom.text(vec(1, 3), Roles::getRoleName(assoc->getItem1()));
			videoBuffer->bg0rom.text(vec(1, 4), "+");
			videoBuffer->bg0rom.text(vec(1, 5), Roles::getRoleName(assoc->getItem2()));
			videoBuffer->bg0rom.text(vec(1, 6), "=");
			videoBuffer->bg0rom.text(vec(1, 7), Roles::getRoleName(assoc->getResult1()));
			videoBuffer->bg0rom.text(vec(1, 8), "+");
			videoBuffer->bg0rom.text(vec(1, 9), Roles::getRoleName(assoc->getResult2()));
		}

	protected:
		Sifteo::VideoMode getVideoMode() const {
			return BG0_ROM;
		}

		virtual void renderElement(VideoBuffer *videoBuffer, const Role role) {
			videoBuffer->bg0rom.erase();
			videoBuffer->bg0rom.text(vec(1, 1), Roles::getRoleName(role));
		}

		virtual void renderHUD(VideoBuffer *videoBuffer, const unsigned char HUDIndex) {
			videoBuffer->bg0rom.erase();
			videoBuffer->bg0rom.text(vec(1, 1), "HUD");
			renderAssoc(videoBuffer, Associations::getAssociation(HUDIndex));
		}

		virtual void renderVillage(VideoBuffer *videoBuffer, const VillageState &villageState) {
			videoBuffer->bg0rom.erase();
			videoBuffer->bg0rom.text(vec(1, 1), "Village");

			String<6> str;
			str << villageState.nextNeed;

			videoBuffer->bg0rom.text(vec(10, 1), str);

			for (int i=0; i<villageState.getNeeds().count(); i++) {
				videoBuffer->bg0rom.text(vec(1, 2+(i*2)), Roles::getRoleName(villageState.getNeeds()[i]));
			}
		}

	public:
		TextRenderer(const GameState *gameState) 
			:AbstractRenderer(gameState) {
				
		}
};

#endif