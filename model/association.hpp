#ifndef ASSOCIATION_HPP
#define ASSOCIATION_HPP

template <typename T>
	class Association_templ {
		private:
			T m_item1;
			T m_item2;
			T m_result1;
			T m_result2;
			bool flag = false;

		public:
			Association_templ(T item1, T item2, T result1, T result2) {
				m_item1 = item1;
				m_item2 = item2;
				m_result1 = result1;
				m_result2 = result2;
			}

			inline bool isSame(T item1, T item2) {
				if (m_item1 == item1 && m_item2 == item2) {
					flag = true;
					return true;
				}

				if (m_item1 == item2 && m_item2 == item1) {
					flag = false;
					return true;
				}

				return false;
			}

			inline T getItem1() const {
				return m_item1;
			}

			inline T getItem2() const {
				return m_item2;
			}

			inline T getResult1() const {
				return flag ? m_result1 : m_result2;
			}

			inline T getResult2() const {
				return flag ? m_result2 : m_result1;
			}
	};

typedef Association_templ<Role> Association;

#endif