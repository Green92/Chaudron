#ifndef REQUESTS_HPP
#define REQUESTS_HPP

#include "request.hpp"

class Requests {
	private:
		Request reqs[10];
		Random rng;

		Request *initRequests() {
			OutcomeArray outcomes;

			outcomes.push_back(Outcome(INSECTS, 10));
			outcomes.push_back(Outcome(PRANCING_EYE, 10));
			outcomes.push_back(Outcome(OCULAR_SHEEP, 20));
			outcomes.push_back(Outcome(SLIME, 50));
			outcomes.push_back(Outcome(ENRAGED_EYE, 100));

			reqs[0] = Request("I need protection...", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(EYES, 10));
			outcomes.push_back(Outcome(EYE_SMOOTHIE, 20));
			outcomes.push_back(Outcome(HALLUCINOGENIC_INFUSION, 10));
			outcomes.push_back(Outcome(EYE_DROPS, 100));

			reqs[1] = Request("I want something for my eyes...", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(INSECTS, 10));
			outcomes.push_back(Outcome(MUSHROOMS, 10));
			outcomes.push_back(Outcome(PRANCING_EYE, 10));
			outcomes.push_back(Outcome(BLINDING_POTION, 50));
			outcomes.push_back(Outcome(POISON_PASTE, 100));
			outcomes.push_back(Outcome(SLUMBER_POTION, 20));
			outcomes.push_back(Outcome(SLIME, 20));
			outcomes.push_back(Outcome(ENRAGED_EYE, 50));
			outcomes.push_back(Outcome(BLINDING_TOBACCO, 50));
			outcomes.push_back(Outcome(LAST_BREAKFAST, 10));
			outcomes.push_back(Outcome(CANCER_COOKIE, 20));

			reqs[2] = Request("I want to harm him...", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(PRANCING_EYE, 10));
			outcomes.push_back(Outcome(POISON_PASTE, 50));
			outcomes.push_back(Outcome(SLIME, 50));
			outcomes.push_back(Outcome(ENRAGED_EYE, 50));
			outcomes.push_back(Outcome(LAST_BREAKFAST, 10));
			outcomes.push_back(Outcome(CANCER_COOKIE, 20));

			reqs[3] = Request("I want to kill him...", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(PRANCING_EYE, 50));
			outcomes.push_back(Outcome(INSECTS, 10));
			outcomes.push_back(Outcome(SLIME, 20));
			outcomes.push_back(Outcome(ENRAGED_EYE, 10));
			outcomes.push_back(Outcome(OCULAR_SHEEP, 100));

			reqs[4] = Request("I need a new pet...", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(INSECTS, 10));
			outcomes.push_back(Outcome(MUSHROOMS, 10));
			outcomes.push_back(Outcome(PRANCING_EYE, 10));
			outcomes.push_back(Outcome(BLINDING_POTION, 50));
			outcomes.push_back(Outcome(POISON_PASTE, 100));
			outcomes.push_back(Outcome(SLUMBER_POTION, 20));
			outcomes.push_back(Outcome(SLIME, 20));
			outcomes.push_back(Outcome(ENRAGED_EYE, 50));
			outcomes.push_back(Outcome(BLINDING_TOBACCO, 50));
			outcomes.push_back(Outcome(LAST_BREAKFAST, 10));
			outcomes.push_back(Outcome(CANCER_COOKIE, 20));

			reqs[5] = Request("I'm hungry...", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(INSECTS, 10));
			outcomes.push_back(Outcome(MUSHROOMS, 10));
			outcomes.push_back(Outcome(PRANCING_EYE, 10));
			outcomes.push_back(Outcome(BLINDING_POTION, 50));
			outcomes.push_back(Outcome(POISON_PASTE, 100));
			outcomes.push_back(Outcome(SLUMBER_POTION, 20));
			outcomes.push_back(Outcome(SLIME, 20));
			outcomes.push_back(Outcome(ENRAGED_EYE, 50));
			outcomes.push_back(Outcome(BLINDING_TOBACCO, 50));
			outcomes.push_back(Outcome(LAST_BREAKFAST, 10));
			outcomes.push_back(Outcome(CANCER_COOKIE, 20));

			reqs[6] = Request("I want to see beyond...", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(EYE_SMOOTHIE , 10));
			outcomes.push_back(Outcome(HALLUCINOGENIC_INFUSION, 50));
			outcomes.push_back(Outcome(PROPHETIC_POWDER, 100));
			outcomes.push_back(Outcome(MINIATURE_ORACLE, 100));
			outcomes.push_back(Outcome(TRUTH_COCKTAIL, 50));

			reqs[7] = Request("I want to know the future...", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(EYE_SMOOTHIE , 50));
			outcomes.push_back(Outcome(HALLUCINOGENIC_INFUSION, 20));
			outcomes.push_back(Outcome(BLINDING_POTION, 10));
			outcomes.push_back(Outcome(SLUMBER_POTION, 100));
			outcomes.push_back(Outcome(TRUTH_COCKTAIL, 50));
			outcomes.push_back(Outcome(EYE_DROPS, 50));

			reqs[8] = Request("I want a drink...", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(EYE_SMOOTHIE , 20));
			outcomes.push_back(Outcome(HALLUCINOGENIC_INFUSION, 100));
			outcomes.push_back(Outcome(PROPHETIC_POWDER, 20));
			outcomes.push_back(Outcome(INSECT_TOBACCO, 500));
			outcomes.push_back(Outcome(TRUTH_COCKTAIL, 20));
			outcomes.push_back(Outcome(MANDRAGORA, 10));
			outcomes.push_back(Outcome(MUSHROOMS , 10));

			reqs[9] = Request("I want to get high...", outcomes);

			return reqs;
		}

	public:
		Requests() {
			initRequests();
		}

		Request *getRandomRequest() {
			return &reqs[rng.randrange<unsigned int>(0, 10)];
		}
};

#endif