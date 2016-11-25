#ifndef REQUESTS_HPP
#define REQUESTS_HPP

#include "request.hpp"

class Requests {
	private:
		Request reqs[10];

		Request *initRequests() {
			OutcomeArray outcomes;

			outcomes.push_back(Outcome(INSECTS, 10));
			outcomes.push_back(Outcome(PRANCING_EYE, 10));
			outcomes.push_back(Outcome(OCULAR_SHEEP, 20));
			outcomes.push_back(Outcome(POINSON_SLIM, 50));
			outcomes.push_back(Outcome(FIERCE_CREATURE, 100));

			reqs[0] = Request("I need protection", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(EYES, 10));
			outcomes.push_back(Outcome(VISION_SMOOTHIE, 20));
			outcomes.push_back(Outcome(HALLUCINOGENIC_INFUSION, 10));
			outcomes.push_back(Outcome(EYES_DROP, 100));

			reqs[1] = Request("I want something for my eyes", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(INSECTS, 10));
			outcomes.push_back(Outcome(MUSHROOMS, 10));
			outcomes.push_back(Outcome(PRANCING_EYE, 10));
			outcomes.push_back(Outcome(BLINDING_POTION, 50));
			outcomes.push_back(Outcome(POISON_PASTE, 100));
			outcomes.push_back(Outcome(SLUMBER_POTION, 20));
			outcomes.push_back(Outcome(POINSON_SLIM, 20));
			outcomes.push_back(Outcome(FIERCE_CREATURE, 50));
			outcomes.push_back(Outcome(BLINDING_TOBACCO, 50));
			outcomes.push_back(Outcome(LAST_BREAKFAST, 10));
			outcomes.push_back(Outcome(CANCER_COOKIE, 20));

			reqs[2] = Request("I want to harm him", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(PRANCING_EYE, 10));
			outcomes.push_back(Outcome(POISON_PASTE, 50));
			outcomes.push_back(Outcome(POINSON_SLIM, 50));
			outcomes.push_back(Outcome(FIERCE_CREATURE, 50));
			outcomes.push_back(Outcome(LAST_BREAKFAST, 10));
			outcomes.push_back(Outcome(CANCER_COOKIE, 20));

			reqs[3] = Request("I want to kill him", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(PRANCING_EYE, 50));
			outcomes.push_back(Outcome(INSECTS, 10));
			outcomes.push_back(Outcome(POINSON_SLIM, 20));
			outcomes.push_back(Outcome(FIERCE_CREATURE, 10));
			outcomes.push_back(Outcome(OCULAR_SHEEP, 100));

			reqs[4] = Request("I need a new pet", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(INSECTS, 10));
			outcomes.push_back(Outcome(MUSHROOMS, 10));
			outcomes.push_back(Outcome(PRANCING_EYE, 10));
			outcomes.push_back(Outcome(BLINDING_POTION, 50));
			outcomes.push_back(Outcome(POISON_PASTE, 100));
			outcomes.push_back(Outcome(SLUMBER_POTION, 20));
			outcomes.push_back(Outcome(POINSON_SLIM, 20));
			outcomes.push_back(Outcome(FIERCE_CREATURE, 50));
			outcomes.push_back(Outcome(BLINDING_TOBACCO, 50));
			outcomes.push_back(Outcome(LAST_BREAKFAST, 10));
			outcomes.push_back(Outcome(CANCER_COOKIE, 20));

			reqs[5] = Request("I'm hungry", outcomes);
			outcomes.clear();

			outcomes.push_back(Outcome(INSECTS, 10));
			outcomes.push_back(Outcome(MUSHROOMS, 10));
			outcomes.push_back(Outcome(PRANCING_EYE, 10));
			outcomes.push_back(Outcome(BLINDING_POTION, 50));
			outcomes.push_back(Outcome(POISON_PASTE, 100));
			outcomes.push_back(Outcome(SLUMBER_POTION, 20));
			outcomes.push_back(Outcome(POINSON_SLIM, 20));
			outcomes.push_back(Outcome(FIERCE_CREATURE, 50));
			outcomes.push_back(Outcome(BLINDING_TOBACCO, 50));
			outcomes.push_back(Outcome(LAST_BREAKFAST, 10));
			outcomes.push_back(Outcome(CANCER_COOKIE, 20));

			reqs[6] = Request("I want to see beyond", outcomes);
			outcomes.clear();
		}

	public:
		static const Request *getRandomRequest() {

		}
};

#endif