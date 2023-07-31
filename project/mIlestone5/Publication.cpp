/*/////////////////////////////////////////////////////////////////////////
						  Milestone4
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.27
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <cstring>
#include "Publication.h"
#include "Utils.h"
#include "Lib.h"
using namespace std;
namespace sdds {
	Publication::Publication() {
		// all the attribute have been created by default
	}

	Publication::~Publication() {
		delete[] m_title;
		m_title = nullptr;
	}

	void Publication::set(int member_id) {
		m_membership = member_id;
	}

	void Publication::setRef(int value) {
		m_libRef = value;
	}

	void Publication::resetDate() {
		Date date;
		m_date = date;
	}

	char Publication::type()const {
		return 'P';
	}

	bool Publication::onLoan()const {
		if (m_membership != 0)
		{
			return true;
		}
		return false;
	}

	Date Publication::checkoutDate()const {
		return m_date;
	}

	bool Publication::operator==(const char* title)const {
		if (strStr(m_title, title) == nullptr)
		{
			return false;
		}
		return true;
	}

	Publication::operator const char* ()const {
		return m_title;
	}

	int Publication::getRef()const {
		return m_libRef;
	}

	bool Publication::conIO(std::ios& io)const {
		if (&io == &cin || &io == &cout)
		{
			return true;
		}
		return false;
	}

	std::ostream& Publication::write(std::ostream& os) const {
		char title[31]{};
		if (conIO(os))
		{
			os << "| " << m_shelfId << " | ";
			if (strLen(m_title) < 30)
			{
				os.setf(ios::left);
				os.width(30);
				os.fill('.');
				os << m_title;
				os << " | ";
			}
			else
			{
				strnCpy(title, m_title, 30);
				os << title;
				os << " | ";
			}
			if (onLoan())
			{
				os << m_membership << " | ";
			}
			else
			{
				os << " N/A  | ";
			}
			os << m_date;
			os << " |";
		}
		else
		{
			os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
		}
		return os;
	}

	std::istream& Publication::read(std::istream& istr) {
		string Cstring;
		string title;
		delete[] m_title;
		m_title = nullptr;
		char shelfId[SDDS_SHELF_ID_LEN+1]{};
		int membership{ 0 };
		int libRef{ -1 };
		Date date;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();
		if (conIO(istr))
		{
			cout << "Shelf No: ";
			// left the new line in buffer
			istr >> Cstring;
			if (Cstring.length() == SDDS_SHELF_ID_LEN)
			{
				 strCpy(shelfId, Cstring.c_str());
				// discard the new line
				 istr.ignore();
			}
			else
			{
				istr.setstate(ios::failbit);
			}
			cout << "Title: ";
			if (!istr.fail())
			{	// ensure that title can get the space
				getline(istr, title);
			}
			cout << "Date: ";
			if (!istr.fail())
			{
				istr >> date;
			}			
			if (!date)
			{
				istr.setstate(ios::failbit);
			}
		}
		else
		{
			istr >> libRef;
			istr.ignore();
			istr >> Cstring;
			if (Cstring.length() == SDDS_SHELF_ID_LEN)
			{
				strCpy(shelfId, Cstring.c_str());
			}
			else
			{
				istr.setstate(ios::failbit);
			}
			if (!istr.fail())
			{
				istr.ignore();
				getline(istr, title, '\t');
				istr >> membership;
				istr.ignore();
				istr >> date;
				if (!date)
				{
					istr.setstate(ios::failbit);
				}
			}
		}
		if (!istr.fail())
		{
			m_title = new char[title.length() + 1];
			strCpy(m_title, title.c_str());
			strCpy(m_shelfId, shelfId);
			m_membership = membership;
			m_date = date;
			m_libRef = libRef;
		}
		return istr;
	}

	Publication::operator bool() const {
		if (m_title != nullptr && m_shelfId[0] != '\0')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Publication::Publication(const Publication& publication) {
		// shallow copy
		strCpy(m_shelfId, publication.m_shelfId);
		m_membership = publication.m_membership;
		m_libRef = publication.m_libRef;
		m_date = publication.m_date;
		// deep copy
		if (publication.m_title!=nullptr)
		{
			m_title = new char[strLen(publication.m_title) + 1];
			strCpy(m_title, publication.m_title);
		}
		else
		{
			m_title = nullptr;
		}
	}

	Publication& Publication::operator=(const Publication& publication) {
		// check for self-assignment
		if (this != &publication) {
			// shallow copy
			strCpy(m_shelfId, publication.m_shelfId);
			m_membership = publication.m_membership;
			m_libRef = publication.m_libRef;
			m_date = publication.m_date;
			// deep copy
			delete[] m_title;
			m_title = nullptr;
			if (publication.m_title != nullptr)
			{
				m_title = new char[strLen(publication.m_title) + 1];
				strCpy(m_title, publication.m_title);
			}
			else
			{
				m_title = nullptr;
			}
		}		
		return *this;
	}

}