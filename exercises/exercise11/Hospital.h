#ifndef HOSPITAL_H_INCLUDED
#define HOSPITAL_H_INCLUDED
#include "Doctor.h"
#include <cstdio>
class Hospital
{
public:
    Hospital();
    Hospital(const Doctor*const*, int);
    Hospital(const Hospital&);
    Hospital& operator = (const Hospital&);
    ~Hospital();

    void addDoctor(const Doctor&);

private:
    void copyArr(const Doctor*const*);
    void copyHospital(const Hospital&);
    void deleteHospital();
    void extend();

    Doctor** arr;
    unsigned size;
    unsigned capacity;

};
#endif // HOSPITAL_H_INCLUDED
