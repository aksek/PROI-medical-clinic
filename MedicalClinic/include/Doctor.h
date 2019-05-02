#include <iostream>
#include <string>

#ifndef DOCTOR_H
#define DOCTOR_H

class Doctor
{
    private:

    public:
	enum Spclty {GP, ophthalmologist, dentist, pediatrist, unspecified};
	const Spclty specialty;
        const std::string name;
        Doctor(): specialty(unspecified), name("unknown") {}
	Doctor(std::string const &nam): specialty(unspecified), name(nam) {}
        Doctor(std::string const &nam, Spclty spec): specialty(spec), name(nam) {}
        bool operator==(Doctor &other);
        friend std::ostream& operator<< (std::ostream& out, const Doctor &doc);
};

#endif // DOCTOR_H
