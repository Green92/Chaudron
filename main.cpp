#include <sifteo.h>
#include "assets.gen.h"

using namespace Sifteo;

static Metadata M = Metadata()
    .title("Proto")
    .package("com.ican.gd.proto", "0.1")
    .icon(Icon)
    .cubeRange(0, CUBE_ALLOCATION);

static VideoBuffer vbuf[CUBE_ALLOCATION];

void onConnect(void* ctxt, unsigned id)
{
    vbuf[id].attach(id);
    vbuf[id].initMode(BG0_ROM);

    // Draw the cube's identity
    CubeID cube(id);
    String<128> str;
    str << "I am cube #" << cube << "\n";
    vbuf[cube].bg0rom.text(vec(1,2), str);
}

 void main() {

 	Events::cubeConnect.set(onConnect);

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