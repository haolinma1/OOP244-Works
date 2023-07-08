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
#include <cstring>
#include "Menu.h"
namespace sdds {
	MenuItem::MenuItem() {
		item = nullptr;
	}

	MenuItem::MenuItem(const char* content) {
		MenuItem();
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
}