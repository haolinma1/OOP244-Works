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
#include "cstring.h"
#include "HtmlText.h"
namespace sdds {

	HtmlText::~HtmlText() {
		delete[] m_title;
		m_title = nullptr;
	}

	HtmlText::HtmlText(const HtmlText& html) :Text(html) {
		
		if (html.m_title != nullptr)
		{
			m_title = new char[strLen(html.m_title) + 1];
			strCpy(m_title, html.m_title);
		}
	}

	HtmlText& HtmlText::operator=(const HtmlText& html) {
		// self-assignment
		if (this != &html)
		{
			delete[] m_title;
			m_title = nullptr;
			if (html.m_title != nullptr)
			{
				m_title = new char[strLen(html.m_title) + 1];
				strCpy(m_title, html.m_title);
			}
			Text::operator=(html);
		}
		return *this;
	}

	HtmlText::HtmlText(const char* filename, const char* title) :Text(filename) {
		if (title != nullptr)
		{
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
	}

	void HtmlText::write(std::ostream& os)const {
		bool MS = false;
		os << "<html><head><title>";
		if (m_title != nullptr)
		{
			os << m_title;
		}
		else
		{
			os << "No Title";
		}
		os << "</title></head>\n<body>\n";
		if (m_title != nullptr)
		{
			os << "<h1>" << m_title << "</h1>\n";
		}
		for (int i = 0; this->operator[](i) != '\0'; i++)
		{
			switch (this->operator[](i))
			{
			case ' ':
				if (MS == true) {
					os << "&nbsp";
				}
				else
				{
					MS = true;
					os << " ";
				}
				break;
			case '<':
				os << "&lt;";
				MS = false;
				break;
			case '>':
				os << "&gt;";
				MS = false;
				break;
			case '\n':
				os << "<br />\n";
				MS = false;
				break;
			default:
				MS = false;
				os << this->operator[](i);
			}

		}
		os << "</body>\n</html>";
	}
}