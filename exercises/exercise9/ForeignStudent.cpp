#include "ForeignStudent.h"

ForeignStudent:: ForeignStudent() : Student("", "", "", 2000), nationality(NULL), address(NULL), fee(0)
{}

ForeignStudent:: ForeignStudent(const char* faculty_number, const char* name, const char* faculty_name, unsigned start_year,
                                const char* nationality, const char* address, unsigned fee) : Student(faculty_number, name, faculty_name, start_year), nationality(NULL), address(NULL)
{
    set_nationality_inner(nationality);
    set_address_inner(address);
    this->fee = fee;
}

ForeignStudent:: ForeignStudent(const ForeignStudent& right) : Student(right)
{
    copy_foreign_student(right);
}

ForeignStudent& ForeignStudent:: operator = (const ForeignStudent& right)
{
    if(this != &right)
    {
        Student:: operator = (right);
        delete_foreign_student();
        copy_foreign_student(right);
    }
    return *this;
}

ForeignStudent:: ~ForeignStudent()
{
    delete_foreign_student();
}

void ForeignStudent:: delete_foreign_student()
{
    delete [] nationality;
    delete [] address;
    this->nationality = NULL;
    this->address = NULL;
}

void ForeignStudent:: copy_foreign_student(const ForeignStudent& right)
{
    set_nationality_inner(right.nationality);
    set_address_inner(right.address);
    this->fee = right.fee;
}

void ForeignStudent:: set_nationality(const char* nationality)
{
    delete [] this->nationality;
    set_nationality_inner(nationality);
}

void ForeignStudent:: set_address(const char* address)
{
    delete [] this->address;
    set_address_inner(address);
}

void ForeignStudent:: set_nationality_inner(const char* nationality)
{
    this->nationality = new char[strlen(nationality) + 1];
    strcpy(this->nationality, nationality);
}

void ForeignStudent:: set_address_inner(const char* address)
{
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}

const char* ForeignStudent:: get_nationality()const
{
    return nationality;
}

const char* ForeignStudent:: get_address()const
{
    return address;
}
