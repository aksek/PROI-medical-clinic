/* Assignment:  Project #2
 *     Author:  Aniela Kosek, 300234
 *     Grader: Wiktor Kuśmirek
 */

#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <string>

#include "Interface.h"
#include "Clinic.h"
#include "Doctor.h"
#include "Patient.h"

using namespace std;


void Interface::menu() {
        vector<string> opts = {"fail", "add a doctor", "remove a doctor", "show all doctors", "add a patient", "remove a patient", "show details on a patient", "add diagnosis", "add prescription", "exit"};
        for (unsigned int i = 1; i < opts.size(); i++) {
            cout << i << ": " << opts[i] << endl;
        }
        int command = 0;
        cin >> command; cin.ignore();
        if (cin.fail()) {
            cerr << "input failed" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            menu();
        }
	switch(command) {
		case 0:
			cerr << "something went wrong" << endl;
			break;
		case 1:
			addDoctor();
			menu();
			break;
		case 2:
			rm<Doctor>();
			menu();
			break;
		case 3:
			this->clinic.printDoctors();
			menu();
			break;
		case 4:
			addPatient();
			menu();
			break;
		case 5:
			rm<Patient>();
			menu();
			break;
		case 6:
			details();
			menu();
			break;
		case 7:
			diagnose();
			menu();
			break;
		case 8:
			prescribe();
			menu();
			break;
		case 9:
			break;
		default:
			cout << "unknown command" << endl;
			menu();
			break;

	}
}

Clinic& Interface::addDoctor() {
	cout << "Type the name of the patient to be added" << endl;
	string name;
	getline(cin, name);
	if (cin.fail()) {
		cin.clear(); cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cerr << "input failed\n";
		return clinic;
	}
	cout << "Choose specialty: 0: GP, 1: ophthalmologist, 2: dentist, 3: pediatrist" << endl;
	int spec_int;
	cin >> spec_int;
	checkInput();
	Doctor::Spclty spec = static_cast<Doctor::Spclty> (spec_int);
	Doctor doc(name, spec);
	this->clinic += doc;
	return this->clinic;
}

Clinic& Interface::addPatient() {
	cout << "Type the name of the patient to be added" << endl;
	string name;
	getline(cin, name);
	checkInput();
	Patient pat(name);
	this->clinic += pat;
	
	return this->clinic;
}

void Interface::details() {
	cout << "Type the name of the patient" << endl;
	string input;
	getline(cin, input);
	checkInput();
	if (!this->clinic.detailsOn(input))
		cerr << "This patient does not exist\n";
}

void Interface::diagnose() {
	cout << "Type the name of the patient" << endl;
	string name;
	getline(cin, name);
	checkInput();
	cout << "Type the diagnosis" << endl;
	string diagnosis;
	getline(cin, diagnosis);
	checkInput();
	clinic.diagnose(name, diagnosis);
}

void Interface::prescribe() {
	cout << "Type the name of the patient" << endl;
	string name;
	getline(cin, name);
	checkInput();
	cout << "Type the prescription" << endl;
	string prescription;
	getline(cin, prescription);
	checkInput();
	clinic.prescribe(name, prescription);
}

inline void Interface::checkInput() {
	if (cin.fail()) {
		cin.clear(); cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cerr << "input failed\n";
		menu();
	}
}