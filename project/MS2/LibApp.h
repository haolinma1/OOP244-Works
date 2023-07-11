#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
namespace sdds {
   class LibApp {
       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;
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
       void checkOutPub();
   public:
       LibApp();

   };
}
#endif // !SDDS_LIBAPP_H



