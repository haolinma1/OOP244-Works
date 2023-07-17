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

#include <iostream>
namespace sdds {
	
	class Shape {

	public:
		virtual void draw(std::ostream& os)const = 0; // pure virtual member function 
		virtual void getSpecs(std::istream& is) = 0; // pure virtual member function
		virtual ~Shape() {}; // no implementation

	};
	std::ostream& operator<<(std::ostream& os, const Shape& shape); // helper function,overload the << operator, return a output and use draw function
	Shape& operator>>(std::istream& is, Shape& shape); // helper function,overload the >> operator return a reference and use getSpecs function.
	
}