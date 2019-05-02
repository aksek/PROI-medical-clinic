#include <iostream>
#include "Clinic.h"
#include "Interface.h"

using namespace std;

int main() {
	Interface* interface = new Interface;
	interface->test();
	interface->menu();
	delete interface;
	return 0;
}
