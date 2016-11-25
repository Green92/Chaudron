#ifndef OUTCOME_HPP
#define OUTCOME_HPP

class Outcome {
	private:
		Role gift;
		int gratification;

	public:
		Outcome() {
			this->gratification = 0;
		}

		Outcome(Role gift, int gratification) {
			this->gift = gift;
			this->gratification = gratification;
		}

		bool match(Role gift) const {
			return this->gift == gift;
		}

		int getGratification() const {
			return gratification;
		}
};

#endif