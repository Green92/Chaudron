#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <sifteo/array.h>

#include "outcome.hpp"

#define MAX_OUTCOME 10

typedef Array<Outcome, MAX_OUTCOME, unsigned char> OutcomeArray;

class Request {
	private:
		const char *req;
		OutcomeArray outcomes;

	public:
		Request(const char *req, OutcomeArray outcomes) {
			this->req = req;
			this->outcomes = outcomes;
		}

		const Outcome *isMatchingOutcome(Role gift) {
			for (OutcomeArray ::iterator oc = outcomes.begin(); oc != outcomes.end(); oc++) {
				if (oc->match(gift)) {
					return &(*oc);
				}
			}

			return NULL;
		}
};

#endif