/* Assignment:  Project #2
 *     Author:  Aniela Kosek, 300234
 *     Grader: Wiktor Kuśmirek
 */

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
