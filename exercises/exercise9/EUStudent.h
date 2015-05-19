#ifndef EUSTUDENT_H_INCLUDED
#define EUSTUDENT_H_INCLUDED
#include "Student.h"

class EUStudent : public Student
{
public:
    EUStudent();
    EUStudent(const char*, const char*, const char*, unsigned, const char*, const char*, const char* const*, unsigned);
    EUStudent(const EUStudent&);
    EUStudent& operator = (const EUStudent&);
    ~EUStudent();

    void set_eucountry(const char*);
    void set_program(const char*);
    void set_languages(const char* const*, unsigned);

    const char* get_eucountry()const;
    const char* get_program()const;
    const char*const * get_languages()const;

private:
    void copy_eustudent(const EUStudent&);
    void delete_eustudent();
    void delete_languages();

    void set_eucountry_inner(const char*);
    void set_program_inner(const char*);
    void set_languages_inner(const char* const*);

    char* eu_country;
    char* program;
    char** languages;
    unsigned languages_number;
};
#endif // EUSTUDENT_H_INCLUDED
