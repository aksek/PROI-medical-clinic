#include <iostream>
#include <set>
#include <string>

#include "Clinic.h"
#include "Doctor.h"

using namespace std;


void Clinic::mock() {
	Doctor doc1("Gregory House", Doctor::pediatrist);
	*this += doc1;
	
	Doctor doc2("Stephen Strange", Doctor::dentist);
	*this += doc2;
	
	Doctor doc3("The Doctor", Doctor::GP);
	*this += doc3;
	
	printDoctors();
	
	Patient pat1("John Doe");
	*this += pat1;
}

Clinic& Clinic::operator+=(Doctor &doc) {
	doctors[doc.specialty].insert(doc);
	return *this;
}

Clinic& Clinic::operator+=(Patient &pat) {
	patients.insert(pat);
	return *this;
}

void Clinic::printDoctors() {
	set<Doctor>::iterator it;
	for (int i = 0; i < nSpecialties; ++i) {
		for (it = doctors[i].begin(); it != doctors[i].end(); ++it) {
			cout << *it << endl;
		}
	}
}

