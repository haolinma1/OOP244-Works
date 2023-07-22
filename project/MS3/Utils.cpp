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

	void strnCpy(char* des, const char* src, int len) {

		int scrLength = 0;

		scrLength = strLen(src);
		if (scrLength >= len)
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


	int strnCmp(const char* s1, const char* s2, int len) {
		int s1Size = 0;
		int s2Size = 0;
		int i = 0;
		int flag = 0;
		s1Size = strLen(s1);
		s2Size = strLen(s2);

		if (s1Size < len)
		{
			for (i = 0; i < s1Size && flag == 0; i++)
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
			for (i = 0; i < len && flag == 0; i++)
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

	
	int strLen(const char* s) {
		int i = 0;

		if (s == nullptr) return 0;

		for (i = 0; s[i] != '\0'; i++)
		{

		}
		return i;
	}


	const char* strStr(const char* str1, const char* str2) {
		int i = 0;
		int j = 0;
		int index = 0;
		int flag = 0;
		int str1Size = strLen(str1);

		for (i = 0; i < str1Size && flag == 0; i++)
		{
			if (str1[i] == str2[0])
			{
				flag = 1;
			}
		}

		if (flag == 0)
		{
			return nullptr;
		}
		else
		{
			i--;
			index = i;
			for (j = 0; j < strLen(str2); j++)
			{
				if (str1[i] != str2[j])
				{
					return nullptr;
				}

				i++;
			}

			return str1 + index;
		}

	}

	void strCat(char* des, const char* src) {
		int desSize = strLen(des);

		int srcSize = strLen(src);
		int i = 0;
		int j = 0;
		for (i = desSize; i < desSize + srcSize; i++)
		{
			des[i] = src[j];
			j++;
		}
		des[i] = '\0';
	}

}