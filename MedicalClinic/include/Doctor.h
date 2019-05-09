/* Assignment:  Project #2
 *     Author:  Aniela Kosek, 300234
 *     Grader:  Wiktor Kuśmirek
 */

#include <iostream>
#include <string>

#ifndef DOCTOR_H
#define DOCTOR_H

class Doctor
{
    public:
	enum class Spclty {GP, ophthalmologist, dentist, pediatrist, unspecified};
        Doctor(): specialty(Spclty::unspecified), name("unknown") {}
	Doctor(std::string const &nam): specialty(Spclty::unspecified), name(nam) {}
        Doctor(std::string const &nam, Spclty spec): specialty(spec), name(nam) {}
        Spclty getSpclty() {return specialty;}
        std::string getName() const {return name;}
        bool operator==(Doctor &other);
        friend std::ostream& operator<< (std::ostream& out, const Doctor &doc);
	
    private:
	const Spclty specialty;
        const std::string name;
};

#endif // DOCTOR_H
