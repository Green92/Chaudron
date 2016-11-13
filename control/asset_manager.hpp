#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include "../assets.gen.h"

#include "../model/role.hpp"

#define NUM_IMG 10

using namespace Sifteo;

typedef struct paire {
	const Role key;
	const AssetImage * image;
} Paire;

/**
 * Charge les assets en memoire
 */

static AssetSlot ElementsSlot = AssetSlot::allocate()
    .bootstrap(Elements);

static AssetSlot FontsSlot = AssetSlot::allocate()
    .bootstrap(Fonts);

class AssetManager {

	static const Paire images[NUM_IMG];

	static const AssetImage * getByRole(Role role) {
		for (int i=0; i<NUM_IMG; i++) {
			if (role == images[i].key) {
				return images[i].image;
			}
		}

		return NULL;
	}
};

#endif