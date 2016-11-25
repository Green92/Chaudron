#ifndef TEXT_RENDERER_HPP
#define TEXT_RENDERER_HPP

#include "abstract_renderer.hpp"

#include "../model/association.hpp"
#include "../model/associations.hpp"

#include <sifteo/string.h>

#define Font Font8

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

		void renderRequest(VideoBuffer *videoBuffer, const char *request) {
			videoBuffer->bg0.image(vec(0,0), Mushrooms);

			drawCenteredTextMultiLine(videoBuffer, 5, request);
		}

		void drawTextMonoLine(VideoBuffer *videoBuffer, UInt2 pos, const char * str) {
			videoBuffer->bg1.fillMask(pos, vec((int)strnlen(str, 16), 1));
			videoBuffer->bg1.text(pos, Font, str);
		}

		void drawCenteredTextMonoLine(VideoBuffer *videoBuffer, int line, const char * str) {
			drawTextMonoLine(videoBuffer, vec((int) (16 - strnlen(str, 16)) / 2, line), str);
		}

		void strcpy(char *dst, const char *src, unsigned char size) {
			unsigned char i;

			for (i = 0; i<size; i++) {
				dst[i] = src[i];
			}

			dst[i] = '\0';
		}

		unsigned char drawCenteredTextMultiLine(VideoBuffer *videoBuffer, int startLine, const char * str) {
			char line[17];
			unsigned char len = strnlen(str, 100);
			int strIndex = 0;
			int nbLine = 0;

			LOG("----------------------------------------\n");
			LOG("Let's print \"%s\" on multiple lines ! Youpi\n", str);
			LOG("Ok, we start to print on line number %d\n", startLine+1);

			while (strnlen(str+strIndex, 100) > 16) {
				
				LOG("\"%s\" is bigger than 16\n", str+strIndex);
				
				for (int i=strIndex+15; i>strIndex; i--) {
					
					LOG("'str at index %d is %c'\n", i, str[i]);
					
					if (str[i] == ' ') {
						strcpy(line, str+strIndex, i-strIndex);
						
						LOG("Ok, printing \"%s\" on line %d\n", line, startLine+nbLine);
						
						drawCenteredTextMonoLine(videoBuffer, startLine+nbLine, line);
						strIndex += i-strIndex+1;
						nbLine++;
						break;
					}
				}

				LOG("strIndex is %d and str is %d char long :  ", strIndex, strnlen(str, 100));

				if (strIndex >= strnlen(str, 100)) {
					LOG("Stopping algorithm.\n");
					return nbLine;
				}

				LOG("We have still some work.\n");
			}

			LOG("\"%s\" is lower than 16\nOk, printing \"%s\" on line %d\n", str+strIndex, str+strIndex, startLine+nbLine);
			drawCenteredTextMonoLine(videoBuffer, startLine+nbLine, str+strIndex);
			return ++nbLine;
		}

	protected:
		Sifteo::VideoMode getVideoMode() const {
			return BG0_BG1;
		}

		virtual void renderElement(VideoBuffer *videoBuffer, const Role role) {
			videoBuffer->bg0.erase();

			switch (role) {
				default:
					//renderElement(vBuf, gameState->cubeRoles[cubeId]);
				break;

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

				case TRUTH_COCKTAIL:
					videoBuffer->bg0.image(vec(0,0), Truth_Cocktail);
				break;

				case LAST_BREAKFAST:
					videoBuffer->bg0.image(vec(0,0), Last_Breakfast);
				break;

				case CANCER_COOKIE:
					videoBuffer->bg0.image(vec(0,0), Cancer_Cookie);
				break;

				case MINIATURE_ORACLE:
					videoBuffer->bg0.image(vec(0,0), Miniature_Oracle);
				break;

			}

			//videoBuffer->bg0rom.text(vec(1, 1), Roles::getRoleName(role));
		}

		virtual void renderHUD(VideoBuffer *videoBuffer, const unsigned char HUDIndex) {
			videoBuffer->bg0.erase();
			videoBuffer->bg0.text(vec(1, 1), Font, "HUD");
			renderAssoc(videoBuffer, Associations::getAssociation(HUDIndex));
		}

		virtual void renderVillage(VideoBuffer *videoBuffer, const VillageState &villageState) {
			videoBuffer->bg0.erase();
			
			drawCenteredTextMonoLine(videoBuffer, 1, "Village");

			if (villageState.currentRequest != NULL)
				renderRequest(videoBuffer, villageState.currentRequest->string());
		}

	public:
		TextRenderer(const GameState *gameState) 
			:AbstractRenderer(gameState) {
				
		}
};

#endif