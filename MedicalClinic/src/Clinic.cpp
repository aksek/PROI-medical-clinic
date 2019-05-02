#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "Clinic.h"
#include "Doctor.h"

using namespace std;


void Clinic::mock() {
	Doctor doc1("Gregory House", Doctor::GP);
	*this += doc1;
	
	Doctor doc2("Stephen Strange", Doctor::GP);
	*this += doc2;
	
	Doctor doc3("The Doctor", Doctor::GP);
	*this += doc3;
	
	printDoctors();
	printDoctors(Doctor::GP);
	
	vector<string> pats = {"John Doe", "Jane Doe", "Dennis", "Polly the Parrot", "Blackbeard", "Zaphod Beeblebrox"};
	vector<string> diags = {"flu", "common cold", "deceased", "pretty sure that one's a parrot", "amputated leg", "absence of brain"};
	for (unsigned int i = 0; i < pats.size(); ++i) {
		Patient pat1(pats[i]);
		pat1.diagnose(diags[i]);
		*this += pat1;
	}
	
	Patient pat2("John Doe");
	
	auto it = patients.find(pat2);
	cout << *it << endl;
	
	printPatients();
	
	Patient pat3 = *it;
	*this -= pat3;
	printPatients();
	
	Doctor doc("Gregory House");
	*this -= doc;
	
	printDoctors();
}

Clinic& Clinic::operator+=(Doctor &doc) {
	doctors[doc.specialty].insert(doc);
	return *this;
}

Clinic& Clinic::operator-=(Doctor &doc) {
	for (int i = 0; i < nSpecialties; ++i)
		doctors[i].erase(doc);
	return *this;
}

Clinic& Clinic::operator+=(Patient &pat) {
	patients.insert(pat);
	return *this;
}

Clinic& Clinic::operator-=(Patient &pat) {
	patients.erase(pat);
	return *this;
}

void Clinic::printDoctors() {
	for (int i = 0; i < nSpecialties; ++i)
		printDoctors(i);
}

void Clinic::printDoctors(int spec) {
	for (set<Doctor>::iterator it = doctors[spec].begin(); it != doctors[spec].end(); ++it)
		cout << *it << endl;
	cout << endl;
}

void Clinic::printPatients() {
	for (set<Patient>::iterator it = patients.begin(); it != patients.end(); ++it)
		cout << *it << endl;
	cout << endl;
}