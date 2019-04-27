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
            bool operator() (T &a, T &b) const {
                return a.getname().compare(b.getname());
            }
        };

        static const short int nSpecialties = 4;
        std::set<Doctor, comp<Doctor> > doctors [nSpecialties];
        std::set<Patient, comp<Patient> > patients;

    public:
        bool add(Doctor &doc);
        bool rm(Doctor &doc);
        bool add(Patient &pat);
        bool rm(Patient &pat);

};

#endif // CLINIC_H
