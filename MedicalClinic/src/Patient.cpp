#include <iostream>
#include <string>
#include "Patient.h"

using namespace std;

Patient::Patient(string nam): name(nam){}

Patient& Patient::diagnose(string const &diagnosis) {
	diagnoses.push_back(diagnosis);
	return *this;
}

bool Patient::operator==(Patient &other) {
	return this->name == other.name;
}

ostream& operator<< (ostream &out, const Patient &pat) {
	out << pat.name << "\nDiagnoses:\n";
	for (unsigned int i = 0; i < pat.diagnoses.size(); ++i) {
		out << pat.diagnoses[i] << '\n';
	}
	return out;
}