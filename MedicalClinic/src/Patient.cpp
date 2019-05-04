/* Assignment:  Project #2
 *     Author:  Aniela Kosek, 300234
 *     Grader: Wiktor Kuśmirek
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Patient.h"

using namespace std;

Patient::Patient(string nam): name(nam){}

Patient& Patient::operator= (Patient other) {
	swap(diagnoses, other.diagnoses);
	swap(prescriptions, other.prescriptions);
	return *this;
}

Patient& Patient::diagnose(string const &diagnosis) {
	diagnoses.push_back(diagnosis);
	return *this;
}

Patient& Patient::prescribe(string const &prescription) {
	prescriptions.push_back(prescription);
	return *this;
}

bool Patient::operator==(Patient &other) {
	return this->name == other.name;
}

ostream& operator<< (ostream &out, const Patient &pat) {
	out << "\nName:\n" << setw(40) << pat.name << "\nDiagnoses:\n";
	for (unsigned int i = 0; i < pat.diagnoses.size(); ++i) {
		out << setw(40) << pat.diagnoses[i] << '\n';
	}
	out << "Prescriptions:\n";
	for (unsigned int i = 0; i < pat.prescriptions.size(); ++i) {
		out << setw(40) << pat.prescriptions[i] << '\n';
	}
	return out;
}