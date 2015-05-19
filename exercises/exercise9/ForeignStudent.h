#ifndef FOREIGNSTUDENT_H_INCLUDED
#define FOREIGNSTUDENT_H_INCLUDED

#include "Student.h"

class ForeignStudent : public Student
{
public:
    ForeignStudent();
    ForeignStudent(const char*, const char*, const char*, unsigned, const char*, const char*, unsigned);
    ForeignStudent(const ForeignStudent&);
    ForeignStudent& operator = (const ForeignStudent&);
    ~ForeignStudent();

    void set_nationality(const char*);
    void set_address(const char*);

    const char* get_nationality()const;
    const char* get_address()const;

private:
    void copy_foreign_student(const ForeignStudent&);
    void delete_foreign_student();

    void set_nationality_inner(const char*);
    void set_address_inner(const char*);

    char* nationality;
    char* address;
    unsigned fee;
};
#endif // FOREIGNSTUDENT_H_INCLUDED
