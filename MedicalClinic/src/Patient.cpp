#include <string>
#include "Patient.h"

using namespace std;

Patient::Patient(string nam): name(nam){}

Patient& Patient::diagnose(string &diagnosis) {
	diagnoses.push_back(diagnosis);
	return *this;
}