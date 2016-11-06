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
			return BG0;
		}

		virtual void renderElement(VideoBuffer *videoBuffer, const Role role) {
			videoBuffer->setMode(BG0);
			videoBuffer->bg0.erase();

			switch (role) {

				case MUSHROOMS:
					videoBuffer->bg0.image(vec(0,0), Mushrooms);
				break;
				case EYES:
					videoBuffer->bg0.image(vec(0,0), Eyes);
				break;
				case MANDRAGORA:
					videoBuffer->bg0.image(vec(0,0), Mandragora);
				break;
				case INSECTS:
					videoBuffer->bg0.image(vec(0,0), Insects);
				break;
				case PRANCING_EYE:
					videoBuffer->bg0.image(vec(0,0), Prancing_Eye);
				break;
				case EYE_SMOOTHIE:
					videoBuffer->bg0.image(vec(0,0), Eye_Smoothie);
				break;
				case ENRAGED_EYE:
					videoBuffer->bg0.image(vec(0,0), Enraged_Eye);
				break;
				case POISON_CAKE:
					videoBuffer->bg0.image(vec(0,0), Poison_Cake);
				break;
				case HALLUCINOGENIC_INFUSION:
					videoBuffer->bg0.image(vec(0,0), Hallucinogenic_Infusion);
				break;
				case OCULAR_SHEEP:
					videoBuffer->bg0.image(vec(0,0), Ocular_Sheep);
				break;
				case POISON_PASTE:
					videoBuffer->bg0.image(vec(0,0), Poison_Paste);
				break;
				case EYE_PORRIDGE:
					videoBuffer->bg0.image(vec(0,0), Eye_Porridge);
				break;
				case BLINDING_POTION:
					videoBuffer->bg0.image(vec(0,0), Blinding_Potion);
				break;
				case SLUMBER_POTION:
					videoBuffer->bg0.image(vec(0,0), Slumber_Potion);
				break;
				case PROPHETIC_POWDER:
					videoBuffer->bg0.image(vec(0,0), Prophetic_Powder);
				break;
				case SLIME:
					videoBuffer->bg0.image(vec(0,0), Slime);
				break;
				case INSECT_TOBACCO:
					videoBuffer->bg0.image(vec(0,0), Insect_Tobacco);
				break;
				case BLINDING_TOBACCO:
					videoBuffer->bg0.image(vec(0,0), Blinding_Tobacco);
				break;
				case EYE_DROPS:
					videoBuffer->bg0.image(vec(0,0), Eye_Drops);
				break;

				default:
					videoBuffer->setMode(BG0_ROM);
					videoBuffer->bg0rom.erase();
					videoBuffer->bg0rom.text(vec(1,1), "Erreur : bloc inconnu");
				break;

			}

			//videoBuffer->bg0rom.text(vec(1, 1), Roles::getRoleName(role));
		}

		virtual void renderHUD(VideoBuffer *videoBuffer, const unsigned char HUDIndex) {
			videoBuffer->setMode(BG0_ROM);
			videoBuffer->bg0rom.erase();
			videoBuffer->bg0rom.text(vec(1, 1), "HUD");
			renderAssoc(videoBuffer, Associations::getAssociation(HUDIndex));
		}

		virtual void renderVillage(VideoBuffer *videoBuffer, const VillageState &villageState) {
			videoBuffer->setMode(BG0_ROM);
			videoBuffer->bg0rom.erase();
			videoBuffer->bg0rom.text(vec(1, 1), "Village");

			String<6> str;
			str << villageState.nextNeed;

			videoBuffer->bg0rom.text(vec(10, 1), str);

			for (int i=0; i<villageState.getNeeds().count(); i++) {
				videoBuffer->bg0rom.text(vec(1, 2+(i*2)), Roles::getRoleName(villageState.getNeeds()[i]));
			}
		}

		virtual void renderText(VideoBuffer *videoBuffer, const Role role) {
			videoBuffer->setMode(BG0_ROM);
			videoBuffer->bg0rom.erase();
			videoBuffer->bg0rom.text(vec(1, 1), Roles::getRoleName(role));
		}

	public:
		TextRenderer(const GameState *gameState) 
			:AbstractRenderer(gameState) {
				
		}
};

#endif