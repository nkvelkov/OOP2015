#include "Hospital.h"


Hospital:: Hospital() : arr(NULL), size(0), capacity(0)
{}

Hospital:: Hospital(const Doctor*const* arr, int size)
{
    this->size = size;
    this->capacity = size;
    copyArr(arr);
}

Hospital:: Hospital(const Hospital& other)
{
    copyHospital(other);
}

Hospital& Hospital:: operator = (const Hospital& other)
{
    if(this != &other)
    {
        deleteHospital();
        copyHospital(other);
    }
    return *this;
}

Hospital:: ~Hospital()
{
    deleteHospital();
}

void Hospital:: addDoctor(const Doctor& doctor)
{
    if(capacity == size)
    {
        extend();
    }
    arr[size++] = doctor.clone();
}

void Hospital:: copyHospital(const Hospital& hospital)
{
    this->capacity = hospital.capacity;
    this->size = hospital.size;
    copyArr(hospital.arr);
}

void Hospital:: deleteHospital()
{
    for(int i = 0; i < size; ++i)
    {
        delete arr[i];
    }
    delete [] arr;
}

void Hospital:: extend()
{
    Doctor** temp = arr;
    capacity *= 2;

    arr = new Doctor*[capacity];
    for(int i = 0; i < size; ++i)
    {
        arr[i] = temp[i]->clone();
    }
    for(int i = 0; i < size; ++i)
    {
        delete temp[i];
    }
    delete [] temp;
}

void Hospital:: copyArr(const Doctor*const* arr)
{
    this->arr = new Doctor*[capacity];
    for(int i = 0; i < size; ++i)
    {
        this->arr[i] = arr[i]->clone();
    }
}
