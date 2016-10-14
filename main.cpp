#include <sifteo.h>

/**
 * Fichier genere à la compilation
 * grace a assets.lua.
 * Contient les image sous forme bitmap.
 */
#include "assets.gen.h"

#include "model/cube.hpp"
#include "model/role.hpp"
#include "model/roles/village.hpp"

/**
 * Espace de nom par defaut
 * 
 */
using namespace Sifteo;

/**
 * Charge les assets en memoire
 */
static AssetSlot MainSlot = AssetSlot::allocate()
    .bootstrap(GameAssets);

/**
 * ?? (definit des meta donnees)
 */
static Metadata M = Metadata()
    .title("Proto")
    .package("com.ican.gd.proto", "0.1")
    .icon(Icon)
    .cubeRange(0, CUBE_ALLOCATION);

/**
 * Contiendra le point d'acces au "Tampon video" de chaque cube.
 */
static VideoBuffer vbuf[CUBE_ALLOCATION];

void setBgImage(unsigned id, const AssetImage& image)
{
    vbuf[id].bg0.image(vec(0,0), image);
}

void onConnect(void* ctxt, unsigned id)
{
    vbuf[id].attach(id);
    vbuf[id].initMode(BG0_BG1);

    setBgImage(id, Background);
}

void onNeighborAdd(
	void* ctxt, unsigned firstID,
    unsigned firstSide, unsigned secondID,
    unsigned secondSide) {

   setBgImage(firstID, Background2);
   setBgImage(secondID, Background2);
}

void onNeighborRemove(
    void* ctxt, unsigned firstID,
    unsigned firstSide, unsigned secondID,
    unsigned secondSide) {

    setBgImage(firstID, Background);
    setBgImage(secondID, Background);
}

 void main() {

 	Events::cubeConnect.set(onConnect);
 	Events::neighborAdd.set(onNeighborAdd);
    Events::neighborRemove.set(onNeighborRemove);

 	// Handle already-connected cubes
    for (CubeID cube : CubeSet::connected())
    {
      onConnect(NULL, cube);
    }

 	// We're entirely event-driven. Everything is
    // updated by SensorListener's event callbacks.
    TimeStep ts;
    while (1)
    {
        System::paint();
        ts.next();
    }
 }