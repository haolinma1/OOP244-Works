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
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
       char* m_title{nullptr};
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr); // constructor
      // rule of three
      virtual ~HtmlText();
      HtmlText(const HtmlText& html);
      HtmlText& operator=(const HtmlText& html);
      void write(std::ostream& os)const; // write the html file content into os

   };
}
#endif // !SDDS_HTMLTEXT_H__
