#ifndef OUTCOME_HPP
#define OUTCOME_HPP

class Outcome {
	private:
		Role gift;
		unsigned char gratification;

	public:
		Outcome() {
			this->gratification = 0;
		}

		Outcome(Role gift, unsigned char gratification) {
			this->gift = gift;
			this->gratification = gratification;
		}

		bool match(Role gift) const {
			return this->gift == gift;
		}

		unsigned char getGratification() const {
			return gratification;
		}
};

#endif