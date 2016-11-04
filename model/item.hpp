#ifndef ITEM_HPP
#define ITEM_HPP

#include <sifteo/asset/image.h>
#include <sifteo/string.h>

#define NAME_MAX_LEN 20

class Item {
	private:
		String<NAME_MAX_LEN> name;
		unsigned char needImportance;
		const AssetImage *image;

	public:
		Item(const char *name = "", const unsigned char needImportance = 0, const AssetImage *image = NULL) {
			this->name = name;
			this->needImportance = needImportance;
			this->image = image;
		}

		inline bool operator== (const Item& other) const {
			return this->name == other.name;
		}
};

#endif