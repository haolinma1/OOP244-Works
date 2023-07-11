/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P1)
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.10
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include "cstring.h"
namespace sdds {
	
	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src) {
		int i = 0;
		for ( i = 0; src[i]!='\0'; i++)
		{
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len) {
		
		int scrLength = 0;

		scrLength = strLen(src);
		if (scrLength >=len)
		{
			for (int j = 0; j < len; j++)
			{
				des[j] = src[j];
			}
			des[len] = '\0';

		}
		else
		{
			int j = 0;
			for (j = 0; j < scrLength; j++)
			{
				des[j] = src[j];
			}
			des[j] = '\0';
		}
	}

	// Compares two C-strings 
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
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
			for ( i = 0; i < s1Length&&flag==0; i++)
			{
				if (s1[i]>s2[i])
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

	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len) {
		int s1Size = 0;
		int s2Size = 0;
		int i = 0;
		int flag = 0;
		s1Size = strLen(s1);
		s2Size = strLen(s2);

		if (s1Size<len)
		{
			for ( i = 0; i < s1Size&&flag==0; i++)
			{
				if (s1[i]>s2[i])
				{
					flag = 1;
				}
				else if (s1[i] < s2[i])
				{
					flag = -1;
				}
			}
			return flag;

		}
		else if (s2Size < len)
		{
			for (i = 0; i < s2Size && flag == 0; i++)
			{
				if (s1[i] > s2[i])
				{
					flag = 1;
				}
				else if (s1[i] < s2[i])
				{
					flag = -1;
				}
			}
			return flag;
		}
		else
		{
			for ( i = 0; i < len && flag == 0; i++)
			{
				if (s1[i] > s2[i])
				{
					flag = 1;
				}
				else if (s1[i] < s2[i])
				{
					flag = -1;
				}

			}
			return flag;
		}
		
	}

	// returns the lenght of the C-string in characters
	int strLen(const char* s) {
		int i = 0;
		
		if (s == nullptr) return 0;
		
		for (i = 0; s[i] != '\0'; i++)
		{

		}
		return i;
	}

	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2) {
		int i = 0;
		int j = 0;
		int index = 0;
		int flag = 0;
		int str1Size = strLen(str1);

		for ( i = 0; i < str1Size && flag==0; i++)
		{
			if (str1[i]==str2[0])
			{
				flag = 1;
			}
		}

		if (flag==0)
		{
			return nullptr;
		}
		else
		{
			i--;
			index = i;
			for ( j = 0; j < strLen(str2); j++)
			{
				if (str1[i]!= str2[j])
				{
					return nullptr;
				}

				i++;
			}
			
			return str1+index;
		}

	}

	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src) {
		int desSize = strLen(des);
		
		int srcSize = strLen(src);
		int i = 0;
		int j = 0;
		for ( i = desSize; i < desSize+srcSize; i++)
		{
			des[i] = src[j];
			j++;
		}
		des[i] = '\0';
	}
}
