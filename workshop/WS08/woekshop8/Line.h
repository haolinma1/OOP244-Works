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
	class Line :public LblShape {
		unsigned m_length{};
	public:
		Line(); // set the m_length to be zero and invoke the base class constructor
		Line(const char* Cstring, unsigned length); // Passes the Cstring to the constructor of the base class
											   // sets the m_length member variable to the value of the second argument.
		virtual ~Line(); // do nothing
		void getSpecs(std::istream& is); // overwrite the base class getSpecs and get the m_length by this function
		void draw(std::ostream& os)const; // print label() and "=" up to m_length if m_length>0 and label()!=nullptr

	}; 
}
