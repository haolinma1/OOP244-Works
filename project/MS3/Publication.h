/*/////////////////////////////////////////////////////////////////////////
						  Milestone3
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.22
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#pragma once
#include <iostream>
#include "Date.h"
#include "Streamable.h"
namespace sdds {
	class Publication :public Streamable {
		char* m_title{ nullptr };
		char m_shelfId[5]{};
		int m_membership{ 0 };
		int m_libRef{ -1 };
		Date m_date;
	public:
		Publication();
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute. 
		bool conIO(std::ios& io)const;
		// Returns true if the address of the io object is the same as 
		// the address of either the cin object or the cout object.
		std::ostream& write(std::ostream& os) const;
		// write method to print shelfId, title, membership and date in sepefic format
		std::istream& read(std::istream& istr);
		// read value from istr and store it in the variable attribute
		operator bool() const;
		// Returns true if neither of the title or shelfId attributes is null or empty.

		// rule of three
		virtual ~Publication();
		Publication(const Publication& publication);
		Publication& operator=(const Publication& publication);
		
	};
}