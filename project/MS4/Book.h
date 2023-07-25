
#include "Publication.h"

namespace sdds {
	class Book :public Publication {
		char* author{nullptr};
	public:
		Book();
		// rule of three
		virtual ~Book();
		Book(const Book& book);
		Book& operator=(const Book& book);
		virtual char type()const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		virtual void set(int member_id);
		operator bool();
	};
}