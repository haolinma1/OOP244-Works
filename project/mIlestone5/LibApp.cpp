/*/////////////////////////////////////////////////////////////////////////
						  Milestone 5
Full Name  :Haolin Ma
Student ID#:129979225
Email      :mhaolin@myseneca.ca
Section    :ZAA
Date       :2023.07.31
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <fstream>
#include <string>
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"
#include "Utils.h"
#include "Lib.h"

using namespace std;
namespace sdds {

	bool LibApp::confirm(const char* message) {
		Menu menu(message);
		menu << "Yes";
		if (menu.run() == 1)
		{

			return true;
		}
		else
		{

			return false;
		}
	}

	void LibApp::load() {
		int i = 0;
		char type{};
		cout << "Loading Data" << endl;
		ifstream infile(fileName);
		for (i = 0; infile; i++)
		{
			infile >> type;
			infile.ignore();
			if (infile)
			{
				if (type == 'P') {
					PPA[i] = new Publication;
				}
				else if (type == 'B')
				{
					PPA[i] = new Book;
				}
				if (PPA[i])
				{
					infile >> *PPA[i];
					NOLP++;
				}
			}
		}

		LLRN = PPA[NOLP - 1]->getRef();
	}

	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream outfile(fileName);
		for (int i = 0; i < NOLP; i++)
		{
			if (PPA[i]->getRef() != 0) {
				outfile << *PPA[i] << endl;
			}
		}
	}

	int LibApp::search(int modes) {
		PublicationSelector selector("Select one of the following found matches:");
		unsigned selection{};
		int libRef{};
		char title[257]{};
		char typeOf{};
		char flag = false;
		selection = m_typeMenu.run();
		while (selection == 0)
		{
			cout << "Aborted!";
			selection = m_typeMenu.run();
		}
		if (selection == 1)
		{
			typeOf = 'B';
		}
		else if (selection == 2)
		{
			typeOf = 'P';
		}
		cout << "Publication Title: ";
		cin.ignore(1000, '\n');
		cin.getline(title, 256);
		for (int i = 0; i < NOLP; i++)
		{
			if (differentModes(modes, i, typeOf, title))
			{
				selector << PPA[i];
				flag = true;
			}
		}
		if (flag == false)
		{
			cout << "No matches found!" << endl;
		}
		else
		{
			selector.sort();
			libRef = selector.run();
			if (libRef == 0)
			{
				cout << "Aborted!"<<endl;
			}
		}
		return libRef;
	}

	bool LibApp::differentModes(int modes, int i, char typeOf, const char* title)const {
		bool selectMode = false;
		if (modes == 1)
		{	// all the publication
			if (title[0]!='\0')
			{
				selectMode = (PPA[i]->getRef() != 0 && PPA[i]->type() == typeOf && PPA[i]->operator==(title));
			}
			else
			{
				selectMode = (PPA[i]->getRef() != 0 && PPA[i]->type() == typeOf);
			}
		}
		else if (modes == 2)
		{
			// only the publication that is on loan
			if (title[0] != '\0')
			{
				selectMode = (PPA[i]->getRef() != 0 && PPA[i]->type() == typeOf && PPA[i]->operator==(title) && PPA[i]->onLoan());
			}
			else
			{
				selectMode = (PPA[i]->getRef() != 0 && PPA[i]->type() == typeOf && PPA[i]->onLoan());
			}
			
		}
		else
		{
			// only available item
			if (title[0] != '\0')
			{
				selectMode = (PPA[i]->getRef() != 0 && PPA[i]->type() == typeOf && PPA[i]->operator==(title) && !PPA[i]->onLoan());
			}
			else
			{
				selectMode = (PPA[i]->getRef() != 0 && PPA[i]->type() == typeOf && !PPA[i]->onLoan());
			}
			
		}
		return selectMode;
	}

	Publication* LibApp::getPub(int libRef) {
		Publication* publication{};
		for (int i = 0; i < NOLP; i++)
		{
			if (PPA[i]->getRef() == libRef)
			{
				publication = PPA[i];
			}
		}
		return publication;
	}

	void LibApp::returnPub() {
		Date currentDate;
		double penalty{};
		cout << "Return publication to the library"<<endl;
		int ref{};
		int i{};
		int delay{};
		bool exit = false;
		ref = search(2);
		for (; i < NOLP && exit == false; i++)
		{
			if (PPA[i]->getRef() == ref)
			{
				cout << *PPA[i] << endl;
				exit = true;
			}
		}
		if (exit == true && confirm("Return Publication?") == 1)
		{
			if (i == 0)
			{
				delay = currentDate - PPA[0]->checkoutDate();
			}
			else
			{
				delay = currentDate - PPA[i - 1]->checkoutDate();
			}
			if (delay > 15) {
				penalty = (delay - 15) * 0.5;
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << "Please pay $" << penalty << " penalty for being " << (delay - 15) << " days late!" << endl;
				cout.unsetf(ios::fixed);
			}
			PPA[i - 1]->set(0);
			m_changed = true;
			cout << "Publication returned" << endl;
		}

	}

	void LibApp::newPublication() {
		unsigned selection{};
		Publication* publication{};
		if (NOLP == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!" << endl;
		}
		else
		{
			cout << "Adding new publication to the library" << endl;
			selection = m_typeMenu.run();
			if (selection == 1)
			{
				publication = new Book;
			}
			else if (selection == 2)
			{
				publication = new Publication;
			}
			else if (selection == 0)
			{
				cout << "Aborted!" << endl;
			}
			if (selection == 1 || selection == 2)
			{
				cin >> *publication;
				if (cin.fail())
				{
					cin.ignore(1000, '\n');
					cout << "Aborted";
				}
				else
				{
					if (!confirm("Add this publication to the library?"))
					{
						cout << "Aborted!";
					}
					else
					{
						if (publication)
						{
							LLRN++;
							publication->setRef(LLRN);
							PPA[NOLP] = publication;
							NOLP++;
							m_changed = true;
							cout << "Publication added" << endl;
						}
						else
						{
							cout << "Failed to add publication!";
							delete publication;
						}
					}
				}
			}
		}
	}

	void LibApp::removePublication() {
		int i = 0;
		int ref{};
		bool exit = false;
		cout << "Removing publication from the library"<<endl;
		ref = search(1);
		for (; i < NOLP && exit == false; i++)
		{
			if (PPA[i]->getRef() == ref) {
				cout << *PPA[i] << endl;
				exit = true;
			}
		}
		if (exit == true && confirm("Remove this publication from the library?") == 1)
		{
			if (i == 0)
			{
				PPA[i]->setRef(0);
			}
			else if (i > 0)
			{
				PPA[i - 1]->setRef(0);
			}
			m_changed = true;
			cout << "Publication removed" << endl;
		}

	}

	void LibApp::checkOutPub() {
		int i = 0;
		int ref{};
		int membership{};
		bool exit = false;
		cout << "Checkout publication from the library" << endl;
		ref = search(3);
		for (;i < NOLP && exit == false; i++)
		{
			if (PPA[i]->getRef() == ref)
			{
				cout << *PPA[i] << endl;
				exit = true;
			}
		}
		if (exit == true && confirm("Check out publication?") == 1)
		{
			cout << "Enter Membership number: ";
			cin >> membership;
			while (membership < 10000 || membership>99999)
			{
				cout << "Invalid membership number, try again: ";
				cin >> membership;
			}
			if (i == 0)
			{
				PPA[0]->set(membership);
			}
			else if (i > 0)
			{
				PPA[i - 1]->set(membership);
			}
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	}

	LibApp::LibApp(const char* name) {
		m_changed = false;
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		m_typeMenu << "Book";
		m_typeMenu << "Publication";
		strCpy(fileName, name);
		load();
	}

	LibApp::~LibApp() {
		for (int i = 0; i < NOLP; i++)
		{
			delete PPA[i];
			PPA[i] = nullptr;
		}
	}

	void LibApp::exit() {
		if (confirm("This will discard all the changes are you sure?"))
		{
			// program terminate
		}
		else
		{
			mainMenu();
		}
	}

	void LibApp::mainMenu() {
		unsigned selection = 0;
		while ((selection = this->m_mainMenu.run()) != 0)
		{
			switch (selection)
			{
			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			}
			cout << endl;
		}
	}

	void LibApp::run() {
		unsigned selection = 0;
		mainMenu();
		bool out = false;
		while (m_changed == true && out == false)
		{

			selection = this->m_exitMenu.run();
			switch (selection)
			{
			case 1:
				save();
				out = true;
				break;
			case 2:
				cout << endl;
				mainMenu();
				break;
			case 0:
				exit();
				out = true;
				break;
			}
		}
		cout << endl << "-------------------------------------------" << endl << "Thanks for using Seneca Library Application" << endl;
	}


}
