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
        m_mainMenu.setTitle("Seneca Libray Application");
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
        }
    }

    void LibApp::run() {
        unsigned selection = 0;
        mainMenu();
        if (m_changed==true)
        {
            selection=this->m_exitMenu.run();
            switch (selection)
            {
            case 1:
                save();
                break;
            case 2:
                mainMenu();
                break;
            case 0:
                exit();
                break;
            }
        }
        cout << endl << "-------------------------------------------" << endl << "Thanks for using Seneca Library Application" << endl;
    }


}
