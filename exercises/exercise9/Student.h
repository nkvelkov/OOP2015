#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
#include <cstring>

class Student
{
public:
    Student();
    Student(const char*, const char*, const char*, unsigned);
    Student(const Student&);
    Student& operator = (const Student&);
    ~Student();

    void set_name(const char*);
    void set_faculty_name(const char*);

    const char* get_faculty_number()const;
    const char* get_name()const;
    const char* get_faculty_name()const;

private:
    void set_name_inner(const char*);
    void set_faculty_name_inner(const char*);

    void copy_student(const Student&);
    void delete_student();

    char faculty_number[11];
    char* name;
    char* faculty_name;
    unsigned start_year;
};

#endif // STUDENT_H_INCLUDED
