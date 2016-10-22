#ifndef ASSOCIATION_HPP
#define ASSOCIATION_HPP

#include "role.hpp"

class Association {
	private:
		Role m_item1;
		Role m_item2;
		Role m_result1;
		Role m_result2;

	public:
		Association(Role item1, Role item2, Role result1, Role result2) {
			m_item1 = item1;
			m_item2 = item2;
			m_result1 = result1;
			m_result2 = result2;
		}

		inline bool isSame(Role item1, Role item2) const {
			return (m_item1 == item1 && m_item2 == item2)
				|| (m_item1 == item2 && m_item2 == item1);
		}

		inline Role getItem1() const {
			return m_item1;
		}

		inline Role getItem2() const {
			return m_item2;
		}

		inline Role getResult1() const {
			return m_result1;
		}

		inline Role getResult2() const {
			return m_result2;
		}
};

#endif