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
#include <fstream>
#include "cstring.h"
#include "Text.h"
using namespace std;
namespace sdds {
	int Text::getFileLength() const {
		int len = 0;
		ifstream fin(m_filename);
		while (fin) {
			fin.get();
			len += !!fin;
		}
		return len;
	}

	Text::Text(const char* filename) {
		if (filename != nullptr)
		{
			m_filename = new char[strLen(filename) + 1];
			strCpy(m_filename, filename);
			read();
		}

	}

	void Text::emptyState() {
		delete[] m_filename;
		m_filename = nullptr;
		delete[] m_content;
		m_content = nullptr;
	}

	const char& Text::operator[](int index)const {
		const char* ret = &nulch;
		if(!(m_content == nullptr || index >= strLen(m_content) || index < 0)) {
			ret =  &m_content[index];
		}
		return *ret;
	}

	Text::~Text() {
		emptyState();
	}

	void Text::init(const Text& text) {
		if (text.m_filename != nullptr)
		{
			m_filename = new char[strLen(text.m_filename) + 1];
			strCpy(m_filename, text.m_filename);
		}
		else
		{
			m_filename = nullptr;
		}
		if (text.m_content != nullptr)
		{
			m_content = new char[strLen(text.m_content) + 1];
			strCpy(m_content, text.m_content);
		}
		else
		{
			m_content = nullptr;
		}
	}

	Text::Text(const Text& text) {
		// shallow copy
		// nothing
		// deep copy
		init(text);
	}

	Text& Text::operator=(const Text& text) {
		// check if self-copy
		if (this != &text)
		{
			// delete the memory
			emptyState();
			init(text);
		}
		return *this;
	}

	void Text::read() {
		int fileSize = getFileLength();
		int i = 0;
		if (fileSize > 0)
		{
			m_content = new char[fileSize + 1];
			ifstream fin(m_filename);
			for (; i < fileSize; i++)
			{
				m_content[i] = fin.get();
			}
			m_content[i] = '\0';
			if(i != fileSize) emptyState(); // fail if reading is incorrect
		}
	}

	void Text::write(std::ostream& os)const {
		if (m_content != nullptr)
		{
			os << m_content;
		}
	}

	std::ostream& operator<<(std::ostream& os, const Text& text) {
		text.write(os);
		return os;
	}


}