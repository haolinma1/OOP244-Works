/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P1)
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.04
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	// Returns the address held in the m_value attribute.
	Line::operator const char* () const {
		return (const char*)m_value;
	}

	// Dynamically allocates memory in m_value and 
	// copies the Cstring pointed by lineContent into it.
	Line& Line::operator=(const char* lineValue) {
		delete[] m_value;
		m_value = new char[strLen(lineValue) + 1];
		strCpy(m_value, lineValue);
		return *this;
	}

	// destructor
	Line::~Line() {
		delete[] m_value;
	}

	// deletes the m_textLines dynamic array, sets is to nullptr
	// deletes the m_filename dynamic , sets is to nullptr
	//  sets m_noOfLines attribute to zero.
	void TextFile::setEmpty() {
		delete[] m_textLines;
		m_textLines = nullptr;
		delete[] m_filename;
		m_filename = nullptr;
		m_noOfLines = 0;
	}

	// if isCopy is false, allocate memory for m_filename, and copy fname 
	// otherwise, allocate memory for m_filename, and 
	// copies the content of the fname argument with a prefix of "C_" attached to it.
	void TextFile::setFilename(const char* fname, bool isCopy) {
		int size = 0;
		if (isCopy == false)
		{
			size = strLen(fname) + 1;
			m_filename = new char[size];
			strCpy(m_filename, fname);
		}
		else
		{
			size = strLen(fname) + 3;
			m_filename = new char[size];
			// in case buffer overrun
			if (size >= 3)
			{
				m_filename[0] = 'C';
				m_filename[1] = '_';
			}
			strCpy(m_filename + 2, fname);
		}
	}

	// Counts the number of lines in the file
	void TextFile::setNoOfLines() {
		ifstream fin(m_filename);
		char c;
		bool empty = true;
		// check if the file has been connected
		if (!fin.is_open())
		{
			//cout << "the file has not been connected";
		}
		else
		{
			while (fin.get(c))
			{
				empty = false;
				if (c == '\n')
				{
					m_noOfLines++;
				}
			}
			if (empty == true)
			{
				// do nothing
			}
			else m_noOfLines++;
		}
		if (m_noOfLines == 0)
		{
			setEmpty();
		}
	}

	// Loads the text file m_filename into the dynamic array of Lines pointed by m_textLines
	void TextFile::loadText() {
		if (m_filename == nullptr)
		{
			// do nothing
		}
		else
		{
			int i = 0;
			delete[] m_textLines;
			m_textLines = nullptr;
			m_textLines = new Line[m_noOfLines];
			ifstream fin(m_filename);
			string line;
			while (getline(fin, line, '\n'))
			{
				m_textLines[i] = line.c_str();
				i++;
			}
			m_noOfLines = i;
		}
	}

	// Saves the content of the TextFile under a new name.
	void TextFile::saveAs(const char* fileName)const {
		ofstream fout(fileName);
		unsigned i = 0;
		if (fout.is_open())
		{
			for (i = 0; i < m_noOfLines; i++)
			{
				fout << m_textLines[i] << endl;
			}
		}
		else
		{
			cout << "The file doesn't open" << endl;
		}
	}

	// Creates an empty TextFile and initializes the m_pageSize attribute using the pageSize argument.
	TextFile::TextFile(unsigned pageSize) {
		m_pageSize = pageSize;
		setEmpty();
	}

	// Initializes the m_pageSize attribute using the pageSize argument
	// all the other attributes to nullptr and zero
	// if the filename is not null, load the file
	TextFile::TextFile(const char* filename, unsigned pageSize) {
		m_pageSize = pageSize;
		setEmpty();
		if (filename != nullptr)
		{
			setFilename(filename);
			setNoOfLines();
			loadText();
		}
	}

	// copy constructor
	TextFile::TextFile(const TextFile& textFile) {
		m_pageSize = textFile.m_pageSize;
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;
		if (textFile)
		{
			setFilename(textFile.m_filename, true);
			textFile.saveAs(m_filename);
			setNoOfLines();
			loadText();
		}
	}

	// copy assignment
	TextFile& TextFile::operator=(const TextFile& textFile) {
		if (*this && textFile)
		{
			delete[] m_textLines;
			m_textLines = nullptr;
			textFile.saveAs(m_filename);
			setNoOfLines();
			loadText();
		}
		return *this;
	}

	// destructor
	TextFile::~TextFile() {
		delete[] m_textLines;
		m_textLines = nullptr;
		delete[] m_filename;
		m_filename = nullptr;
	}

	// returns m_noOfLines;
	unsigned TextFile::lines()const {
		return m_noOfLines;
	}

	// Prints the filename and then the content of the file "m_pageSize" lines at a time.
	std::ostream& TextFile::view(std::ostream& ostr)const {
		if (*this)
		{
			int i = 0;
			int sizeOfName = strLen(m_filename);
			ostr << m_filename << endl;
			for (i = 0; i < sizeOfName; i++)
			{
				ostr << '=';
			}
			ostr << endl;
			i = 0;
			while (i < m_noOfLines)
			{
				ostr << m_textLines[i] << endl;
				i++;
				if (i % m_pageSize == 0)
				{
					
					cout << "Hit ENTER to continue...";
					if (cin.rdbuf()->in_avail() > 0)
					{
						cin.ignore();
					}
					
					cin.get();
				}
			}
		}
		return ostr;
	}

	// Receives a filename to set the file name of Textfile
	// set the number of lines and load the text
	std::istream& TextFile::getFile(std::istream& istr) {
		string fileName;
		istr >> fileName;
		setFilename(fileName.c_str());
		setNoOfLines();
		loadText();
		return istr;
	}

	// Returns the element in the m_textLine array corresponding to the index argument.
	const char* TextFile::operator[](unsigned index)const {
		unsigned realIndex = 0;
		if (!*this)
		{
			return NULL;
		}
		if (index >= m_noOfLines)
		{
			realIndex = index % m_noOfLines;
			return m_textLines[realIndex];
		}
		return m_textLines[index];
	}

	// Returns true if the TextFile is not in an empty state and returns false if it is.
	TextFile::operator bool()const {
		if (m_filename != nullptr && m_textLines != nullptr)
		{
			return true;
		}
		return false;
	}

	// Returns the filename.
	const char* TextFile::name()const {
		return m_filename;
	}

	// uses the view() method to print the TextFile
	ostream& operator<<(ostream& ostr, const TextFile& text) {
		return text.view(ostr);
	}

	// uses the getFile() method to get the file name from console
	// load the content from the file
	istream& operator>>(istream& istr, TextFile& text) {
		return text.getFile(istr);
	}





}