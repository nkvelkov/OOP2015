#include "Student.h"

Student:: Student() : name(NULL), faculty_name(NULL)
{
    this->faculty_number[0] = '\0';
    this->start_year = 2000;
}

Student:: Student(const char* faculty_number, const char* name, const char* faculty_name, unsigned start_year) : name(NULL), faculty_name(NULL)
{
    strcpy(this->faculty_number, faculty_number);

    set_name_inner(name);
    set_faculty_name_inner(faculty_name);

    this->start_year = start_year;
}

Student:: Student(const Student& right_student) : name(NULL), faculty_name(NULL)
{
    copy_student(right_student);
}

Student& Student:: operator = (const Student& right_student)
{
    if(this != &right_student)
    {
        delete_student();
        copy_student(right_student);
    }
    return *this;
}

Student:: ~Student()
{
    delete_student();
}

void Student:: copy_student(const Student& right_student)
{
    strcpy(this->faculty_number, right_student.faculty_number);

    set_name_inner(right_student.name);
    set_faculty_name_inner(right_student.faculty_name);

    this->start_year = right_student.start_year;
}

void Student:: delete_student()
{
    delete [] name;
    delete [] faculty_name;
    this->name = NULL;
    this->faculty_name = NULL;
}

void Student:: set_name(const char* name)
{
    delete [] this->name;
    set_name_inner(name);
}

void Student:: set_faculty_name(const char* faculty_name)
{
    delete [] this->faculty_name;
    set_faculty_name_inner(faculty_name);
}

void Student:: set_name_inner(const char* name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Student:: set_faculty_name_inner(const char* faculty_name)
{
    this->faculty_name = new char[strlen(faculty_name) + 1];
    strcpy(this->faculty_name, faculty_name);
}

const char* Student:: get_faculty_number()const
{
    return faculty_number;
}

const char* Student:: get_name() const
{
    return name;
}

const char* Student:: get_faculty_name() const
{
    return faculty_name;
}
