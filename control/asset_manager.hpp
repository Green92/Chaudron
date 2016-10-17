#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include "../assets.gen.h"

#define NUM_IMG 10

using namespace Sifteo;

typedef struct paire {
	const char *key;
	const AssetImage * image;
} Paire;

/**
 * Charge les assets en memoire
 */
static AssetSlot MainSlot = AssetSlot::allocate()
    .bootstrap(GameAssets);

class AssetManager {

	static const Paire images[NUM_IMG];

	static const AssetImage * getByName(const char *name) {
		for (int i=0; i<NUM_IMG; i++) {
			if (strncmp(name, images[i].key, 30) == 0) {
				return images[i].image;
			}
		}

		return NULL;
	}
};

#endif