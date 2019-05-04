
/* Assignment:  Project #2
 *     Author:  Aniela Kosek, 300234
 *     Grader: Wiktor Kuśmirek
 */

#include <limits>
#include <iostream>
#include <string>

#include "Clinic.h"
#include "Doctor.h"
#include "Patient.h"

#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

class Interface {
private:
	Clinic clinic;
public:
	void menu();
	void test() {clinic.mock();}
	Clinic& addDoctor();
	Clinic& addPatient();
	template <typename T>
	Clinic& rm() {
		std::cout << "Type the name of the person to be removed" << std::endl;
		std::string input;
		getline(std::cin, input);
		if (!std::cin.fail()) {
			T torm(input);
			return (clinic -= torm);
			
		} else 
			std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return clinic;
	}
	void details();
	void diagnose();
	void prescribe();
	inline void checkInput();
};

#endif // INTERFACE_H_INCLUDED
