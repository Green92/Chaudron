#ifndef ROLES_HPP
#define ROLES_HPP

#include "role.hpp"

const Sifteo::AssetImage NullImage = {

};

//Special blocks
#define CAULDRON	0

//primary elements
#define EYES		1
#define INSECTS		2
#define MANDRAGORA 	3
#define MUSHROOMS 	4

//secondary elements
#define EYE_SMOOTHIE 			5
#define PRANCING_EYE 			6
#define POISON_PASTE 			7
#define INSECT_TOBACCO			8
#define HALLUCINOGENIC_INFUSION	9
#define BLINDING_POTION			10

//level 3 final elements
#define EYE_PORRIDGE		11
#define OCULAR_SHEEP		12
#define SLIME				13
#define POISON_CAKE			14
#define PROPHETIC_POWDER	15
#define SLUMBER_POTION		16

//level 4 final elements
#define LAST_BREAKFAST		17
#define ENRAGED_EYE			18
#define MINIATURE_ORACLE	19
#define CANCER_COOKIE 		20
#define BLINDING_TOBACCO	21
#define TRUTH_COCKTAIL		22
#define EYE_DROPS			23

#define ROLE_NUMBER 24

const static Sifteo::AssetImage roles_images[] = {
	Cauldron,
	Eyes,
	Insects,
	Mandragora,
	Mushrooms,
	Eye_Smoothie,
	Prancing_Eye,
	Poison_Paste,
	Insect_Tobacco,
	Hallucinogenic_Infusion,
	Blinding_Potion,
	Eye_Porridge,
	Ocular_Sheep,
	Slime,
	Poison_Cake,
	Prophetic_Powder,
	Slumber_Potion,
	Last_Breakfast,
	Enraged_Eye,
	Miniature_Oracle,
	Cancer_Cookie,
	Blinding_Tobacco,
	Truth_Cocktail,
	Eye_Drops
};

const static Role initialRoles[MAX_CUBES] = { 
	CAULDRON,
	MANDRAGORA, INSECTS,
	EYES,		MUSHROOMS,
	MANDRAGORA, INSECTS,
	EYES,		MUSHROOMS
};

class Roles {
	public:
		inline static const AssetImage *getRoleImage(Role role) {
			return &roles_images[role];
		}

		inline static Role getInitialRole(unsigned id) {
			return initialRoles[id];
		}
};

#endif