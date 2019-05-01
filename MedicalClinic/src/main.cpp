#include <iostream>
#include "Clinic.h"
#include "Interface.h"

using namespace std;

int main() {
	Clinic clinic;
	clinic.mock();
	Interface interface;
	interface.menu();
	//delete clinic;
	return 0;
}
