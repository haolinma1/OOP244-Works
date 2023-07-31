/*/////////////////////////////////////////////////////////////////////////
						  Milestone 5
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.31
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
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
	Book::Book(const Book& book) :Publication(book) {
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
			os.setf(ios::left);
			os.width(15);
			os.fill(' ');
			os << authorName << " |";
			os.unsetf(ios::left);
		}
		else
		{
			os << '\t';
			os << author;
		}
		return os;
	}

	std::istream& Book::read(std::istream& istr) {
		char buffer[1000];
		Publication::read(istr);
		delete[] author;
		author = nullptr;
		if (conIO(istr))
		{
			istr.ignore();
			cout << "Author: ";
			istr.getline(buffer, 1000);
		}
		else
		{
			istr.ignore();
			istr.get(buffer, 1000);
		}
		if (!istr.fail())
		{
			author = new char[strLen(buffer) + 1];
			strCpy(author, buffer);
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