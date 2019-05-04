/* Assignment:  Project #2
 *     Author:  Aniela Kosek, 300234
 *     Grader: Wiktor Kuśmirek
 */

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
	
	vector<string> pats = {"John Doe", "Jane Doe", "Dennis", "Polly the Parrot", "Blackbeard", "Zaphod Beeblebrox"};
	vector<string> diags = {"flu", "common cold", "deceased", "pretty sure that one's a parrot", "amputated leg", "absence of brain"};
	vector<string> pres = {"climbing trees", "brain surgery", "vitamin C", "aspirin", "apirin", "new brain"};
	for (unsigned int i = 0; i < pats.size(); ++i) {
		Patient pat1(pats[i]);
		pat1.diagnose(diags[i]);
		pat1.prescribe(pres[i]);
		*this += pat1;
	}
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
	cout << endl;
}

void Clinic::printDoctors(int spec) {
	for (set<Doctor>::iterator it = doctors[spec].begin(); it != doctors[spec].end(); ++it)
		cout << *it << endl;
}

void Clinic::printPatients() {
	for (set<Patient>::iterator it = patients.begin(); it != patients.end(); ++it)
		cout << *it << endl;
	cout << endl;
}

bool Clinic::detailsOn(std::string const &name) {
	Patient pat(name);
	auto it = patients.find(pat);
	if (it != patients.end()) {
		cout << *it << std::endl;
		return true;
	} else 
		return false;
}

void Clinic::diagnose(std::string const &name, std::string const &diagnosis) {
	Patient pat(name);
	auto it = patients.find(pat);
	if (it != patients.end()) {
		pat = *it;
		patients.erase(it);
	}
	pat.diagnose(diagnosis);
	*this += pat;
}

void Clinic::prescribe(std::string const &name, std::string const &prescription) {
	Patient pat(name);
	auto it = patients.find(pat);
	if (it != patients.end()) {
		pat = *it;
		patients.erase(it);
	}
	pat.prescribe(prescription);
	*this += pat;
}