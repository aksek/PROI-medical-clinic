#include<string>
#include<vector>

#ifndef PATIENT_H
#define PATIENT_H


class Patient
{
    private:
	std::vector<std::string> diagnoses;
	std::vector<std::string> prescriptions;
    public:
	const std::string name;
        Patient(){}
        Patient(std::string nam);
	Patient& operator= (Patient other);
	Patient& diagnose (std::string const &diagnosis);
	Patient& prescribe (std::string const &prescription);
	bool operator==(Patient &other);
	friend std::ostream& operator<< (std::ostream& out, const Patient &pat);
};

#endif // PATIENT_H
