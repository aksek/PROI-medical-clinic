#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "../include/Interface.h"

using namespace std;

void menu() {
        vector<string> opts = {"add a patient", "remove a patient", "add a doctor", "remove a doctor", "exit"};
        for (int i = 0; i < opts.size(); i++) {
            cout << i << ": " << opts[i] << endl;
        }
        int command;
        cin >> command;
        if (cin.fail()) {
            cerr << "input failed" << endl;
            cin.clear();
            cin.ignore();
            menu();
        }
    switch(command) {
        case 0:
            cout << "the feature for adding patients is still being developed" << endl;
            menu();
            break;
        case 1:
            cout << "the feature for removing patients is still being developed" << endl;
            menu();
            break;
        case 2:
            cout << "the feature for adding doctors is still being developed" << endl;
            menu();
            break;
        case 3:
            cout << "the feature for removing doctors is still being developed" << endl;
            menu();
            break;
        case 4:
            break;
        default:
            cout << "unknown command" << endl;
            menu();
            break;

    }
}
