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
#include "Rectangle.h"
using namespace std;
namespace sdds {
	Rectangle::Rectangle() :LblShape() {
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* Cstring, int width, int height) : LblShape(Cstring) {
		m_width = width;
		m_height = height;
		if (m_height < 3 || m_width < strlen(label()) + 2)
		{
			m_width = 0;
			m_height = 0;
		}
	}

	Rectangle::~Rectangle() {
		// do nothing
	}

	void Rectangle::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore();
		is >> m_height;
		while (is.get() != '\n')
		{
			// do nothing
		}
	}

	void Rectangle::draw(std::ostream& os)const {
		// not empty state
		if (m_width != 0 && m_height != 0)
		{	// first line
			os << "+";
			os.fill('-');
			os.width(m_width - 2);
			os << "+" << endl;
			// second line
			os << "|";
			os.fill(' ');
			os.width(m_width - 3);
			os.setf(ios::left);
			os << label();
			os.unsetf(ios::left);
			os << "|" << endl;
			// in next (m_height - 3) lines
			for (int i = 0; i < m_height - 3; i++)
			{
				os << "|";
				os.width(m_width - 2);
				os<<"|" << endl;
			}
			// last line
			os << "+";
			os.fill('-');
			os.width(m_width - 2);
			os << "+";
		}
	}
}