/*/////////////////////////////////////////////////////////////////////////
						  Milestone1
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.06
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <cstring>
#include "Menu.h"

using namespace std;
namespace sdds {
	MenuItem::MenuItem() {
		item = nullptr;
	}

	MenuItem::MenuItem(const char* content) {
		item = nullptr;
		item = new char[strlen(content) + 1];
		strcpy(item, content);
	}

	MenuItem::~MenuItem() {
		delete[] item;
		item = nullptr;
	}

	MenuItem::operator bool()const {
		if (item == nullptr)
		{
			return false;
		}
		return true;
	}

	MenuItem::operator const char* ()const {
		return item;
	}

	std::ostream& MenuItem::display(std::ostream& os) {
		if (!*this)
		{
			// do nothing
		}
		else
		{
			os << item;
		}
		return os;
	}

	// the functions for Menu class
	Menu::Menu() {
		numOfItem=0;
	}

	Menu::Menu(const char* title) {
		m_title.item = new char[strlen(title) + 1];
		strcpy(m_title.item, title);
		numOfItem = 0;
	}

	Menu::~Menu() {
		for (int i = 0; i < numOfItem; i++)
		{
			menuItem[i]->~MenuItem();
			menuItem[i] = nullptr;
		}
	}

	std::ostream& Menu::displayTitle(std::ostream& os)const {
		// title is not empty
		if (this->m_title)
		{
			os << this->m_title;
		}
		return os;
	}

	std::ostream& Menu::displayWholeMenu(std::ostream& os)const {
		displayTitle(os);
		os << ":" << endl;
		for (int i = 0; i < numOfItem; i++)
		{
			os << i + 1 << "- "; 
			menuItem[i]->display(os);
			cout << endl;
		}
		os << "0- Exit" << endl;
		os << "> ";
		return os;
	}

	unsigned Menu::run()const {
		unsigned selection = 0;
		displayWholeMenu();
		cin >> selection;
		while (cin.fail()||selection> numOfItem)
		{	// clear the buffer
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Selection, try again: ";
			cin >> selection;
		}
		return selection;
	}

	unsigned Menu::operator~()const {
		return this->run();
	}

	Menu& Menu::operator<<(const char* menuitemConent) {
		// check if the next spot is available
		if (numOfItem< MAX_MENU_ITEMS)
		{
			menuItem[numOfItem]->item = new char[strlen(menuitemConent) + 1];
			strcpy(menuItem[numOfItem]->item, menuitemConent);
			numOfItem++;
		}
		else
		{
			// do nothing
		}
		return *this;
	}

	Menu::operator int()const {
		return this->numOfItem;
	}

	Menu::operator bool()const {
		if (numOfItem>0)
		{
			return true;
		}
		return false;
	}

	std::ostream& Menu::operator<<(const Menu& menu)const {
		return menu.displayTitle();
	}



}