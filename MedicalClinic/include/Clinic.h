/* Assignment:  Project #2
 *     Author:  Aniela Kosek, 300234
 *     Grader: Wiktor Kuśmirek
 */

#include <set>
#include <string>
#include "Doctor.h"
#include "Patient.h"

#ifndef CLINIC_H
#define CLINIC_H


class Clinic {
    private:
        template <typename T>
        class comp {
	public:
            bool operator()(const T &a, const T &b) const {
                return (a.name).compare(b.name) < 0;
            }
        };

        static const short int nSpecialties = 4;
        std::set<Doctor, comp<Doctor> > doctors [nSpecialties];
        std::set<Patient, comp<Patient> > patients;

    public:
	void mock();
	Clinic& operator+=(Doctor &doc);
        Clinic& operator-=(Doctor &doc);
        Clinic& operator+=(Patient &pat);
        Clinic& operator-=(Patient &pat);
	void printDoctors();
	void printDoctors(int spec);
	void printPatients();
	bool detailsOn(std::string const &name);
	void diagnose(std::string const &name, std::string const &diagnosis);
	void prescribe(std::string const &name, std::string const &prescription);
};

#endif // CLINIC_H
