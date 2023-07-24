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
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
   class Text {
       char* m_filename{nullptr};
      char* m_content{ nullptr };
      int getFileLength()const; // it returns the length (size) of the text file on the disk. 
                                // It returns zero if either the file does not exist or the content is empty.
      void emptyState(); // set this class to empty state
      void init(const Text& text); // allocate memory and copy for the copy constructor and operator
   protected:
      const char& operator[](int index)const; // return the element in m_content with index
   public:
      Text(const char* filename=nullptr);
      // Rule of three
      virtual ~Text();
      Text(const Text& text);
      Text& operator=(const Text& text);

      void read(); // store the content of file into m_content
      virtual void write(std::ostream& os)const; // output m_content into os
   };
    std::ostream& operator<<(std::ostream&,const Text& text); // overload << to output Text object into os
}
#endif // !SDDS_PERSON_H__

