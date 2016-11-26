#ifndef TEXT_RENDERER_HPP
#define TEXT_RENDERER_HPP

#include "abstract_renderer.hpp"

#include "text_render_util.hpp"

class GameRenderer : public AbstractRenderer {

	private:
		const GameModel *gameModel;

	protected:
		Sifteo::VideoMode getVideoMode() const {
			return BG0_BG1;
		}

		void renderCube(unsigned char id, Sifteo::VideoBuffer *videoBuffer) {
			Role role = gameModel->getCubeRole(id);

			videoBuffer->bg0.erase();
			videoBuffer->bg1.erase();

			videoBuffer->bg0.image(vec(0,0), *(Roles::getRoleImage(role)));

			if (role == CAULDRON && gameModel->getCurrentRequest() != NULL) {
				TextRenderUtil::drawCenteredTextMultiLine(
					videoBuffer, 5, gameModel->getCurrentRequest()->getString(), 1
				);
			}
		}

	public:
		GameRenderer(const GameModel *gameModel) {
			this->gameModel = gameModel;
		}
};

#endif