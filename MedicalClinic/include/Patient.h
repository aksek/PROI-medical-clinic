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
	//std::string getname() {return name;}
	Patient& diagnose (std::string const &diagnosis);
	bool operator==(Patient &other);
	friend std::ostream& operator<< (std::ostream& out, const Patient &pat);
};

#endif // PATIENT_H
