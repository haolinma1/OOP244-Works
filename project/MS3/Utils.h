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
	void strCpy(char* des, const char* src); // Copies the srouce character string into the destination
	void strnCpy(char* des, const char* src, int len);// Copies the source character string into the destination upto "len"
													  // characters. The destination will be null terminated only if the number
													  // of the characters copied is less than "len"
	int strCmp(const char* s1, const char* s2);// Compares two C-strings 
											   // returns 0 i thare the same
											   // return > 0 if s1 > s2
											   // return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len); 	// returns 0 i thare the same
															// return > 0 if s1 > s2
															// return < 0 if s1 < s2
	int strLen(const char* s); // returns the lenght of the C-string in characters
	const char* strStr(const char* str1, const char* str2); 	// returns the address of first occurance of "str2" in "str1"
																// returns nullptr if no match is found
	void strCat(char* des, const char* src); // Concantinates "src" C-string to the end of "des"
}
#endif // SDDS_UTILS_H__
