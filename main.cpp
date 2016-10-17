#include <sifteo.h>

/**
 * Fichier genere à la compilation
 * grace a assets.lua.
 * Contient les image sous forme bitmap.
 */
#include "assets.gen.h"

#include "control/asset_manager.hpp"

#include "control/game.hpp"

/**
 * Espace de nom par defaut
 * 
 */
using namespace Sifteo;

/**
 * ?? (definit des meta donnees)
 */
static Metadata M = Metadata()
    .title("Proto")
    .package("com.ican.gd.proto", "0.1")
    .icon(Icon)
    .cubeRange(0, CUBE_ALLOCATION);

 void main() {

 	static Game game;

    game.run();

 }