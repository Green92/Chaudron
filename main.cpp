#include <sifteo.h>

/**
 * Fichier genere à la compilation
 * grace a assets.lua.
 * Contient les image sous forme bitmap.
 */
#include "assets.gen.h"

#include "control/game.hpp"

#include "control/game_state.hpp"
#include "control/menu_state.hpp"
 #include "control/score_state.hpp"

/**
 * Espace de nom par defaut
 * 
 */
using namespace Sifteo;

/**
 * ?? (definit des meta donnees)
 */
 static Metadata M = Metadata()
    .title("Usine bunker")
    .package("com.ican.proto", "1")
    .cubeRange(0, CUBE_ALLOCATION)
    .icon(Icon);

/**
 * Charge les images en memoire
 */
static AssetSlot ElementsSlot = AssetSlot::allocate()
    .bootstrap(Elements);

/**
 * Charge les polices en memoire
 */
static AssetSlot FontsSlot = AssetSlot::allocate()
    .bootstrap(Fonts);

/**
 * Charge les images du menu en memoire
 */
static AssetSlot MenuSlot = AssetSlot::allocate()
    .bootstrap(MenuImages);


/**
 * Point d'entree du programme
 */
 void main() {

 	static Game game;

 	static VideoBuffer vBuf[MAX_CUBES];

 	static ScoreState scoreState(&game, vBuf);
 	static GameState gameState(&game, vBuf, &scoreState);
 	static StartMenuState menuState(&game, vBuf, &gameState);

 	scoreState.setNextState(&menuState);

 	game.runState(&menuState);

    game.run();

 }