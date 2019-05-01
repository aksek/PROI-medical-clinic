#include <iostream>
#include <string>
#include "Doctor.h"

using namespace std;


ostream& operator<< (ostream &out, const Doctor &doc) {
	const char* s = 0;
#define PROCESS(p) case(p): s = #p; break;
	switch(doc.specialty) {
		PROCESS(Doctor::GP);
		PROCESS(Doctor::ophthalmologist);
		PROCESS(Doctor::dentist);
		PROCESS(Doctor::pediatrist);
		PROCESS(Doctor::unspecified);
	}
#undef PROCESS
	string str = s;
	size_t pos = str.find(":");
	pos += 2;
	return out << doc.name << ": " << str.substr(pos);
}