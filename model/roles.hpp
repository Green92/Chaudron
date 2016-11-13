#ifndef ROLES_HPP
#define ROLES_HPP

#include "role.hpp"

//Special blocks
#define CAULDRON	0
#define HUD			1
#define DEBUG_PLUS 	2
#define DEBUG_MINUS 3

//primary elements
#define EYES		4
#define INSECTS		5
#define MANDRAGORA 	6
#define MUSHROOMS 	7

//secondary elements
#define EYE_SMOOTHIE 			8
#define PRANCING_EYE 			9
#define POISON_PASTE 			10
#define INSECT_TOBACCO			11
#define HALLUCINOGENIC_INFUSION	12
#define BLINDING_POTION			13

//level 3 final elements
#define EYE_PORRIDGE		14
#define OCULAR_SHEEP		15
#define SLIME				16
#define POISON_CAKE			17
#define PROPHETIC_POWDER	18
#define SLUMBER_POTION		19

//level 4 final elements
#define LAST_BREAKFAST		20
#define ENRAGED_EYE			21
#define MINIATURE_ORACLE	22
#define CANCER_COOKIE 		23
#define BLINDING_TOBACCO	24
#define TRUTH_COCKTAIL		25
#define EYE_DROPS			26

#define ROLE_NUMBER 27

const static char *roles_names[] = {
	 "Chaudron",
	 "HUD",
	 "DEBUG_PLUS",
	 "DEBUG_MINUS",
	 "Yeux",
	 "Insectes",
	 "Mandragore",
	 "Champignons",
	 "Smoothie de Vision",
	 "Oeil Sauteur",
	 "Pate empoisonnee",
	 "Tabac d'Insectes",
	 "Infusion Hallucinogene",
	 "Potion d'Aveuglement",
	 "Porridge aux Yeux",
	 "Mouton Oculaire",
	 "Slime",
	 "Gateau Empoisonne",
	 "Poudre Prophétique",
	 "Potion de Sommeil",
	 "Dernier P'tit Dej",
	 "Oeil Enrage",
	 "Oracle Miniature",
	 "Cookie au Cancer",
	 "Tabac Aveuglant",
	 "Cocktail de la Verité",
	 "Gouttes pour les yeux"

};

const static Role initialRoles[MAX_CUBES] = { 
	CAULDRON,
	MANDRAGORA,
	INSECTS, 	EYES,
	MUSHROOMS, 	MANDRAGORA,
	INSECTS, 	EYES,
	MUSHROOMS, 	MANDRAGORA,
	DEBUG_PLUS, DEBUG_MINUS
};

const static unsigned char needs[] = {
		// **Special blocks
	0,	// VILLAGE
	0,	// HUD

	0,  // DEBUG_PLUS
	0,  // DEBUG_MINUS

		// **primary elements
	2,	// EYES
	2,	// INSECTS
	2,	// MANDRAGORA
	2,	// MUSHROOMS

		// **one association elements
	2,	// EYE_SMOOTHIE
	2,	// PRANCING_EYE
	2,	// POISON_PASTE
	2,	// INSECT_TOBACCO
	2,	// HALLUCINOGENIC_INFUSION
	2,	// BLINDING_POTION

		// **two associations elements
	2,	// EYE_PORRIDGE
	2,	// OCULAR_SHEEP
	2,	// SLIME
	2,	// POISON_CAKE
	2,	// ORACLE_POWDER
	2,	// SLUMBER_POTION

		// **three associations elements
	2,	//LAST_BREAKFAST
	2,	//ENRAGED_EYE
	2,	//MINIATURE_ORACLE
	2,	//CANCER_COOKIE
	2,	//BLINDING_TOBACCO
	2,	//TRUTH_COCKTAIL
	2	//EYE_DROPS
};

class Roles {
	public:
		inline static const char *getRoleName(Role role) {
			return roles_names[role];
		}

		inline static bool isPrimaryElement(Role role) {
			return role >= EYES && role <= MUSHROOMS;
		}

		inline static Role getInitialRole(unsigned id) {
			return initialRoles[id];
		}

		inline static Role getNeed(Role need) {
			return needs[need];
		}
};

#endif