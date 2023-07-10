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

	int strCmp(const char* s1, const char* s2) {
		int s1Length = 0;
		int s2Length = 0;

		int i = 0;
		int flag = 0;

		s1Length = strLen(s1);
		s2Length = strLen(s2);
		if (s1Length > s2Length)
		{
			return 1;
		}
		else if (s1Length < s2Length)
		{
			return -1;

		}
		else
		{
			for (i = 0; i < s1Length && flag == 0; i++)
			{
				if (s1[i] > s2[i])
				{
					flag = 1;
				}
				else if (s1[i] < s2[i]) {
					flag = -1;
				}
			}
			return flag;

		}
	}

}