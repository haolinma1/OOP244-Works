#include <iostream>
#include "LibApp.h"
using namespace std;
namespace sdds {

    bool LibApp::confirm(const char* message) {
        Menu menu(message);
        menu << "yes";
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
        
    }

}
