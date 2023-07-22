
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

	/*Publication::~Publication() {
		delete[] m_title;
		m_title = nullptr;
	}*/

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
		if (conIO(os))
		{
			os << "| " << m_shelfId << " | ";
			os.setf(ios::left);
			os.width(30);
			os.fill('.');
			os << m_title;
			os << " | ";
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
		char ch = '0';
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
			istr.ignore();
			while ((ch = istr.get()) != '\t') {
				title += ch;
			}
			istr >> membership;
			istr.ignore();
			istr >> date;
			if (!date)
			{
				istr.setstate(ios::failbit);
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

}