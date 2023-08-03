/*/////////////////////////////////////////////////////////////////////////
						  Workshop 10
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.08.02
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"
namespace sdds {

	/// <summary>
	/// return true if one of the element match the array, and add the matching element into the collection
	/// </summary>
	/// <typeparam name="type">can be any type</typeparam>
	/// <param name="collection"></param>
	/// <param name="arr">the operator == should be overload in order for comparison</param>
	/// <param name="num"></param>
	/// <param name="key">the operator == should be overload in order for comparison</param>
	/// <returns></returns>
	template <typename type1, typename type2>
	bool search(Collection<type1>& collection, type1 arr[], int num, type2 key) {
		bool result = false;
		for (int i = 0; i < num; i++)
		{
			if (arr[i] == key) {
				result = true;
				collection.add(arr[i]);
			}
		}
		return result;
	}

	/// <summary>
	/// print the element in the array by the num
	/// </summary>
	/// <typeparam name="type">can be any type</typeparam>
	/// <param name="title"></param>
	/// <param name="arr">the operator << shoule be overload in order to be printed</param>
	/// <param name="num"></param>
	template <typename type>
	void listArrayElements(const char* title, const type arr[], int num) {
		std::cout << title << std::endl;
		for (int i = 0; i < num; i++)
		{
			std::cout << i+1 << ": " << arr[i] << std::endl;
		}
	}
}



#endif