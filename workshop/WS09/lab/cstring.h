/*/////////////////////////////////////////////////////////////////////////
						  Workshop9
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.24
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#pragma once

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

