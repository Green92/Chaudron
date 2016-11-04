#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <sifteo/array.h>

#include "item.hpp"

#define MAX_ITEMS 30

#define LEVEL_1 4
#define LEVEL_2 3
#define LEVEL_3 2
#define LEVEL_4 1

typedef Array<Item, MAX_ITEMS, unsigned char> ItemArray;

class Items {
	private:
		ItemArray items;

	public:
		Items() {
			items.append(Item("Fire", 			LEVEL_1));
			items.append(Item("Ground", 		LEVEL_1));
			items.append(Item("Tool", 			LEVEL_1));
			items.append(Item("Water", 			LEVEL_1));

			items.append(Item("Steam", 			LEVEL_2));
			items.append(Item("Brick", 			LEVEL_2));
			items.append(Item("Wood", 			LEVEL_2));
			items.append(Item("Campfire", 		LEVEL_2));
			items.append(Item("Fishing boat", 	LEVEL_2));		
		}

		unsigned char count() const {
			return items.count();
		}

		const Item *itemFromName(const char *name) {
			unsigned char index = items. find(Item(name));

			ASSERT(index != items.NOT_FOUND);

			return &items[index]; 
		}
};

#endif