#include <string>
#include "../include/Doctor.h"

using namespace std;

Doctor::Doctor(){}
Doctor::Doctor(string nam, Spclty spec) {
    name = nam;
    specialty = spec;
}
