#include <set>
#include <string>
#include "Doctor.h"
#include "Patient.h"

#ifndef CLINIC_H
#define CLINIC_H


class Clinic {
    private:
        template <typename T>
        class comp {				//class template
            bool operator() (T &a, T &b) const {
                return a.getname().compare(b.getname());
            }
        };

        static const short int nSpecialties = 4;
        std::set<Doctor, comp<Doctor> > doctors [nSpecialties];
        std::set<Patient, comp<Patient> > patients;

    public:
	void mock();
        bool operator+=(Doctor &doc);		//operator overload
        bool operator-=(Doctor &doc);
        bool operator+=(Patient &pat);
        bool operator-=(Patient &pat);
	bool printDoctors();			//iterator, function overload
	bool printDoctors(Spclty spec);	
};

#endif // CLINIC_H
