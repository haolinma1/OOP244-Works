#include <iostream>
#include <cstring>
#include <string>
#include "Utils.h"
#include "Book.h"
#include "Lib.h"
using namespace std;
namespace sdds {
	Book::Book() {
		
	}
	// rule of three
	Book::~Book() {
		delete[] author;
		author = nullptr;
	}
	Book::Book(const Book& book):Publication(book) {
		if (book.author != nullptr)
		{
			author = new char[strLen(book.author) + 1];
			strCpy(author, book.author);
		}
	}
	Book& Book::operator=(const Book& book) {
		// self-assignment
		if (this != &book)
		{
			delete[] author;
			author = nullptr;
			if (book.author != nullptr)
			{
				author = new char[strLen(book.author) + 1];
				strCpy(author, book.author);
			}
			Publication::operator=(book);
		}
		return *this;
	}

	char Book::type()const {
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const {
		char authorName[SDDS_AUTHOR_WIDTH + 1];
		Publication::write(os);
		if (conIO(os))
		{
			os << " ";
			strnCpy(authorName, author, SDDS_AUTHOR_WIDTH);
			os << authorName << " |";
		}
		else
		{
			os << '\t';
			os << author;
		}
		return os;
	}

	std::istream& Book::read(std::istream& istr) {
		string authoName;
		Publication::read(istr);
		delete[] author;
		author = nullptr;
		if (conIO(istr))
		{
			istr.ignore();
			cout << "Author: ";
			getline(istr, authoName);
		}
		else
		{
			istr.ignore();
			getline(istr, authoName);
		}
		if (!istr.fail())
		{
			author = new char[authoName.length() + 1];
			strCpy(author, authoName.c_str());
		}
		return istr;
	}

	void Book::set(int member_id) {
		Publication::set(member_id);
		// reset the date to current date
		resetDate();
	}

	Book::operator bool() {
		if (author != nullptr && strLen(author) > 0 && Publication::operator bool())
		{
			return true;
		}
		return false;
	}
}