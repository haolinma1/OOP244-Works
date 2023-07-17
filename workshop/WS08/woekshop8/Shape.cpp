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
#include "Shape.h"
using namespace std;
namespace sdds {

	std::ostream& operator<<(std::ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	}
	Shape& operator>>(std::istream& is, Shape& shape) {
		shape.getSpecs(is);
		return shape;
	}
}