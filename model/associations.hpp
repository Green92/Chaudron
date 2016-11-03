#ifndef ASSOCIATIONS_HPP
#define ASSOCIATIONS_HPP

#include "roles.hpp"

const static Association assocs[] = {

	//one association
	Association (EYES, MANDRAGORA, EYE_SMOOTHIE, MANDRAGORA),
	Association (INSECTS, EYES, PRANCING_EYE, EYES),
	Association (INSECTS, MUSHROOMS, POISON_PASTE, MUSHROOMS),
	Association (MANDRAGORA, INSECTS, INSECT_TOBACCO, INSECTS),
	Association (MANDRAGORA, MUSHROOMS, HALLUCINOGENIC_INFUSION, MUSHROOMS),
	Association (MUSHROOMS, EYES, BLINDING_POTION, EYES),

	//two associations
	Association (EYE_SMOOTHIE, INSECTS, EYE_PORRIDGE, INSECTS),
	Association (PRANCING_EYE, EYES, OCULAR_SHEEP, EYES),
	Association (POISON_PASTE, EYES, SLIME, EYES),
	Association (POISON_PASTE, MANDRAGORA, POISON_CAKE, MANDRAGORA),
	Association (INSECT_TOBACCO, MUSHROOMS, PROPHETIC_POWDER, MUSHROOMS),
	Association (BLINDING_POTION, MANDRAGORA, SLUMBER_POTION, MANDRAGORA),

	//three associations
	Association (EYE_SMOOTHIE, POISON_PASTE, LAST_BREAKFAST, POISON_PASTE),
	Association (PRANCING_EYE, INSECT_TOBACCO, ENRAGED_EYE, INSECT_TOBACCO),
	Association (PRANCING_EYE, HALLUCINOGENIC_INFUSION, MINIATURE_ORACLE, HALLUCINOGENIC_INFUSION),
	Association (POISON_PASTE, INSECT_TOBACCO, CANCER_COOKIE, INSECT_TOBACCO),
	Association (INSECT_TOBACCO, BLINDING_POTION, BLINDING_TOBACCO, BLINDING_POTION),
	Association (HALLUCINOGENIC_INFUSION, BLINDING_POTION, TRUTH_COCKTAIL, BLINDING_POTION),
	Association (BLINDING_POTION, EYE_SMOOTHIE, EYE_DROPS, EYE_SMOOTHIE)

};

//Thank you to increase when adding an association
#define ASSOCIATIONS_NUMBER 19

class Associations {
	public:
		static const Association *search(Role item1, Role item2) {
			for (unsigned char i=0; i<ASSOCIATIONS_NUMBER; i++) {
				if (assocs[i].isSame(item1, item2)) {
					return &assocs[i];
				}
			}

			return NULL;
		}

		static const Association *getAssociation(unsigned char index) {
			return &assocs[index];
		}
};

#endif