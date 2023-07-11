/*/////////////////////////////////////////////////////////////////////////
						  Milestone2
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.11
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#define MAX_MENU_ITEMS 20
namespace sdds {
	class MenuItem {
		char* item;
		MenuItem();// set to empty state
		MenuItem(const char* content);
		MenuItem(const MenuItem&) = delete; // not allow to copy through constructor or assignment
		MenuItem& operator=(const MenuItem&) = delete;
		~MenuItem(); // deallocate the memory
		operator bool()const; // true if it is not empty, false otherwise
		operator const char* ()const; // return the address of content Cstring
		std::ostream& display(std::ostream& os = std::cout); // display the menuitem
		friend class Menu;
	};

	class Menu {
		MenuItem m_title;
		MenuItem* menuItem[MAX_MENU_ITEMS]{ nullptr };
		unsigned numOfItem;
	public:
		Menu(const Menu&) = delete; // not allow to copy through constructor or assignment
		Menu& operator=(const Menu&) = delete;
		Menu(); // empty state
		Menu(const char* title); // create the menu with title
		~Menu(); // deallocate the memory 
		std::ostream& displayTitle(std::ostream& os = std::cout)const;
		std::ostream& displayWholeMenu(std::ostream& os = std::cout)const;
		unsigned run()const; // display the menu and ask for the selection
		unsigned operator~()const; // display the menu and ask for the selection
		Menu& operator<<(const char* menuitemConent); // add a menuitem to the menu
		operator bool()const; // return true if the menu has at least one item, false otherwise
		operator unsigned int()const; // return the number of items in the menu		
		char* operator[](unsigned index)const; // return the string of item with the index
		void setTitle(const char* title);
	};
	std::ostream& operator<<(std::ostream& cout, const Menu& menu); // display the menu title by overloading the << 
}