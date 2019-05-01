#include<string>
#include<vector>

#ifndef PATIENT_H
#define PATIENT_H


class Patient
{
    private:
        std::string name;
	std::vector<std::string> diagnoses;
    public:
        Patient();
        Patient(std::string nam);
	std::string getname() {return name;}
	Patient& diagnose (const std::string diagnosis);
};

#endif // PATIENT_H
