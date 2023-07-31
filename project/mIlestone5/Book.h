/*/////////////////////////////////////////////////////////////////////////
						  Milestone 5
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.31
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include "Publication.h"

namespace sdds {
	class Book :public Publication {
		char* author{ nullptr };
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