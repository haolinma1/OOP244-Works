/*/////////////////////////////////////////////////////////////////////////
						  Milestone4
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.27
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include "Streamable.h"
namespace sdds {
	Streamable::~Streamable() {
		// do nothing
	}

	std::ostream& operator<<(std::ostream& os, const Streamable& streamable) {
		if (streamable)
		{
			return streamable.write(os);
		}
		else return os;
	}

	std::istream& operator>>(std::istream& is, Streamable& streamable) {
		return streamable.read(is);
	}
}