#include "Clinic.h"
#include "Doctor.h"
#include "Patient.h"

#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

class Interface {
public:
	void menu();
	bool makeDoctor(std::string name, Spclty spec);
	bool makePatient(std::string name);
	template <typename T>			//function template
	bool rm(const std::string name, Clinic &clinic) {
		T torm(name);
		bool check = (clinic -= torm);
		return check;
	}
};

#endif // INTERFACE_H_INCLUDED
