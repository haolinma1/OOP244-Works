/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version 1
// Date 2023/7/10
// Author	Haolin Ma
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 		
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Utils.h"
namespace sdds {
	void strCpy(char* des, const char* src) {
		int i = 0;
		for (i = 0; src[i] != '\0'; i++)
		{
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	int strLen(const char* s) {
		int i = 0;

		if (s == nullptr) return 0;

		for (i = 0; s[i] != '\0'; i++)
		{

		}
		return i;
	}

}