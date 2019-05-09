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
        const std::string name;
        Doctor(): name("unknown"), specialty(Spclty::unspecified) {}
	Doctor(std::string const &nam): name(nam), specialty(Spclty::unspecified) {}
        Doctor(std::string const &nam, Spclty spec): name(nam), specialty(spec) {}
        Spclty getSpclty() {return specialty;}
        bool operator==(Doctor &other);
        friend std::ostream& operator<< (std::ostream& out, const Doctor &doc);
	
    private:
	const Spclty specialty;
};

#endif // DOCTOR_H
