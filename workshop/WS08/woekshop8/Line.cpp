/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.17
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "Line.h"
using namespace std;
namespace sdds {
	Line::Line() :LblShape() {
		m_length = 0;
	}

	Line::Line(const char* Cstring, unsigned length) :LblShape(Cstring) {
		m_length = length;
	}

	Line::~Line() {
		// do nothing
	}

	void Line::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		// clear the buffer
		while (is.get() != '\n')
		{
			// do nothing
		}
	}

	void Line::draw(std::ostream& os)const {
		if (m_length > 0 && label() != nullptr)
		{
			os << label() << endl;
			for (unsigned i = 0; i < m_length; i++)
			{
				os << "=";
			}
		}
	}
}