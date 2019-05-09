/* Assignment:  Project #2
 *     Author:  Aniela Kosek, 300234
 *     Grader:  Wiktor Kuśmirek
 */

#include <iostream>
#include <string>
#include "Doctor.h"

using namespace std;

bool Doctor::operator==(Doctor &other) {
	return this->name == other.name;
}

ostream& operator<< (ostream &out, const Doctor &doc) {
	const char* s = 0;
#define PROCESS(p) case(p): s = #p; break;
	switch(doc.specialty) {
		PROCESS(Doctor::Spclty::GP);
		PROCESS(Doctor::Spclty::ophthalmologist);
		PROCESS(Doctor::Spclty::dentist);
		PROCESS(Doctor::Spclty::pediatrist);
		PROCESS(Doctor::Spclty::unspecified);
	}
#undef PROCESS
	string str = s;
	size_t pos = str.find("y:");
	pos += 3;
	return out << doc.name << ": " << str.substr(pos);
}