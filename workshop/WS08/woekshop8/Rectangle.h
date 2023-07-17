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
#pragma once
#include "LblShape.h"

namespace sdds {
	class Rectangle :public LblShape {
		int m_width{};
		int m_height{};
	public:
		Rectangle(); // set m_width and m_height to 0 and invoke base class constructor
		Rectangle(const char* Cstring, int width, int height); // set label and m_width and m_height based on arguments
		virtual ~Rectangle(); // no implementation
		void getSpecs(std::istream& is); // write information to label, m_width and m_height
		void draw(std::ostream& os)const; // display a rectangle that contained the label in format
	}; 
}
