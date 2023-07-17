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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LblShape.h"
using namespace std;
namespace sdds {

	const char* LblShape::label()const {
		return m_label;
	}

	LblShape::LblShape() {
		// do nothing
	}

	LblShape::LblShape(const char* Cstring) {
		m_label = new char[strlen(Cstring) + 1];
		strcpy(m_label, Cstring);
	}

	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}

	 void LblShape::getSpecs(std::istream& is) {
		 string label;
		 char ch{};
		 while ((ch=is.get())!=',')
		 {
			 label += ch;
		 }
		 m_label = new char[label.length() + 1];
		 strcpy(m_label, label.c_str());
		 
	 }
}