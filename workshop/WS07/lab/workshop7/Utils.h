/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 1
// Date	2023/7/10
// Author	Haolin Ma
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {
	void strCpy(char* des, const char* src); // copy the src string to des
	int strLen(const char* s); // get the length of the string
	int strCmp(const char* s1, const char* s2); // Compares two C-strings returns 0 if thare the same return > 0 if s1 > s2 return < 0 if s1 < s2
}
#endif // SDDS_UTILS_H__
