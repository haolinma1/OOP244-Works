/*/////////////////////////////////////////////////////////////////////////
                          Milestone2
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.12
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
namespace sdds {
   class LibApp {
       bool m_changed;
       Menu m_mainMenu{ "Seneca Library Application" };
       Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?" };
       bool confirm(const char* message); // Instantiate a Menu
       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       void search();  // prints: "Searching for publication"<NEWLINE>

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
       void newPublication(); // add a new publication and check if the user want it
       void removePublication(); // check if the user want to remove the publication
       void checkOutPub(); // calls the confirm method with Check out publication?"
                           // if confrim returns true, it will set m_changed to true and prints "Publication checked out" + newline
       void exit(); // display the exit message and ask if the user want to exit
   public:
       LibApp(); // constructor
       void run(); // run the app 
       void mainMenu(); // run the main menu

   };
}
#endif // !SDDS_LIBAPP_H



