#include <sifteo.h>

/**
 * Fichier genere à la compilation
 * grace a assets.lua.
 * Contient les image sous forme bitmap.
 */
#include "assets.gen.h"

#include "control/asset_manager.hpp"

#include "control/game.hpp"
#include "control/game_state.hpp"

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

 void main() {

 	static Game game;
 	static GameState playState(&game);

 	game.runState(&playState);

    game.run();

 }