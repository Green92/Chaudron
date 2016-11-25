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

			reqs[0] = Request("I need protection");
			outcomes.clear();

			outcomes.push_back(Outcome(EYES, 10));
			outcomes.push_back(Outcome(VISION_SMOOTHIE, 20));
			outcomes.push_back(Outcome(HALLUCINOGENIC_INFUSION, 10));
			outcomes.push_back(Outcome(EYES_DROP, 100));

			reqs[1] = Request("I want something for my eyes");
			outcomes.clear();
		}

	public:
		static const Request *getRandomRequest() {

		}
};

#endif