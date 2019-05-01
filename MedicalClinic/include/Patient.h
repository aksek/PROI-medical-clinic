#include<string>
#include<vector>

#ifndef PATIENT_H
#define PATIENT_H


class Patient
{
    private:
	std::vector<std::string> diagnoses;
    public:
	const std::string name;
        Patient(){}
        Patient(std::string nam);
	std::string getname() {return name;}
	Patient& diagnose (std::string &diagnosis);
};

#endif // PATIENT_H
