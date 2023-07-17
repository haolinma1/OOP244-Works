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

#include "Shape.h"

namespace sdds {
	class LblShape :public Shape {
		char* m_label{ nullptr };
	protected:
		const char* label()const; //  returns the unmodifiable value of m_label member variable.

	public:
		LblShape(); // zero argument constructor, do nothing
		LblShape(const char* Cstring); // copy the argument string to m_label 
		virtual ~LblShape(); // delte the m_label
		LblShape(const LblShape&) = delete; // delete the copy and assignment constructor
		LblShape& operator=(const LblShape&) = delete;
		virtual void draw(std::ostream& os)const = 0;
		virtual void getSpecs(std::istream& is); // write into the m_label
	};
}
