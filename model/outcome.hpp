#ifndef OUTCOME_HPP
#define OUTCOME_HPP

class Outcome {
	private:
		Role gift;
		const  char *response;
		unsigned char gratification;

	public:
		Outcome() {
			this->gratification = 0;
			this->response = "";
		}

		Outcome(Role gift, const char *response , unsigned char gratification) {
			this->gift = gift;
			this->response = response;
			this->gratification = gratification;
		}

		bool match(Role gift) const {
			return this->gift == gift;
		}

		const char * getResponse() const {
			return response;
		}

		unsigned char getGratification() const {
			return gratification;
		}
};

#endif