#include <string>

#ifndef DOCTOR_H
#define DOCTOR_H

enum Spclty {generalPractitioner, ophthalmologist, dentist, pediatrist};
class Doctor
{
    private:
        std::string name;
        Spclty specialty;
    public:
        Doctor();
        Doctor(std::string nam, Spclty spec);
        std::string getname() {return name;}
};

#endif // DOCTOR_H
