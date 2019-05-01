#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "Interface.h"

using namespace std;


void Interface::menu() {
        vector<string> opts = {"fail", "add a patient", "remove a patient", "add a doctor", "remove a doctor", "exit"};
        for (unsigned int i = 1; i < opts.size(); i++) {
            cout << i << ": " << opts[i] << endl;
        }
        int command = 0;
        cin >> command;
        if (cin.fail()) {
            cerr << "input failed" << endl;
            cin.clear();
	    cin.sync();
            cin.ignore();
            menu();
        }
    switch(command) {
	case 0:
	    cout << "something went wrong" << endl;
	    break;
        case 1:
            cout << "the feature for adding patients is still being developed" << endl;
            menu();
            break;
        case 2:
            cout << "the feature for removing patients is still being developed" << endl;
            menu();
            break;
        case 3:
            cout << "the feature for adding doctors is still being developed" << endl;
            menu();
            break;
        case 4:
            cout << "the feature for removing doctors is still being developed" << endl;
            menu();
            break;
        case 5:
            break;
        default:
            cout << "unknown command" << endl;
            menu();
            break;

    }
}
