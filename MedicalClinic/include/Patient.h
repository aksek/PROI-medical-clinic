/* Assignment:  Project #2
 *     Author:  Aniela Kosek, 300234
 *     Grader:  Wiktor Kuśmirek
 */

#include<string>
#include<vector>

#ifndef PATIENT_H
#define PATIENT_H


class Patient
{
    private:
	std::vector<std::string> diagnoses;
	std::vector<std::string> prescriptions;
	const std::string name;
    public:
        Patient(){}
        Patient(std::string nam);
	Patient& operator= (Patient other);
	Patient& diagnose (std::string const &diagnosis);
	Patient& prescribe (std::string const &prescription);
	std::string getName() const {return name;}
	bool operator==(Patient &other);
	friend std::ostream& operator<< (std::ostream& out, const Patient &pat);
};

#endif // PATIENT_H
