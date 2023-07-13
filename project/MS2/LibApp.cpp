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
#include <iostream>
#include "LibApp.h"
using namespace std;
namespace sdds {

    bool LibApp::confirm(const char* message) {
        Menu menu(message);
        menu << "Yes";
        if (menu.run()==1)
        {
            
            return true;
        }
        else
        {
         
            return false;
        }
    }

    void LibApp::load() {
        cout << "Loading Data" << endl;
    }

    void LibApp::save() {
        cout << "Saving Data" << endl;
    }

    void LibApp::search() {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub() {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        m_changed = true;
    }

    void LibApp::newPublication() {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?"))
        {
            m_changed = true;
            cout << "Publication added" << endl;
        }
    }

    void LibApp::removePublication() {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?"))
        {
            m_changed = true;
            cout << "Publication removed" << endl;
        }
    }

    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?"))
        {
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
    }

    LibApp::LibApp() {
        m_changed = false;
        m_mainMenu.setTitle("Seneca Library Application");
        m_mainMenu << "Add New Publication";
        m_mainMenu << "Remove Publication";
        m_mainMenu << "Checkout publication from library";
        m_mainMenu << "Return publication to library";
        m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
        m_exitMenu << "Save changes and exit";
        m_exitMenu << "Cancel and go back to the main menu";
        load();
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
        while (m_changed==true&& out ==false)
        {   

            selection=this->m_exitMenu.run();
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
