#include "EUStudent.h"

EUStudent:: EUStudent() : Student("", "", "", 2000), eu_country(NULL), program(NULL), languages(NULL)
{
    this->languages_number = 0;
}

EUStudent:: EUStudent(const char* faculty_number, const char* name, const char* faculty_name, unsigned start_year,
                      const char* eucountry, const char* program, const char* const* languages, unsigned languages_number) :
                      Student(faculty_number, name, faculty_name, start_year), eu_country(NULL), program(NULL), languages(NULL)
{
    set_eucountry_inner(eucountry);
    set_program_inner(program);
    this->languages_number = languages_number;
    set_languages_inner(languages);
}

EUStudent:: EUStudent(const EUStudent& right) : Student(right)
{
    copy_eustudent(right);
}

EUStudent& EUStudent:: operator = (const EUStudent& right)
{
    if(this != &right)
    {
        Student:: operator = (right);
        delete_eustudent();
        copy_eustudent(right);
    }
    return *this;
}
EUStudent:: ~EUStudent()
{
    delete_eustudent();
}

void EUStudent:: copy_eustudent(const EUStudent& right)
{
    set_eucountry_inner(right.eu_country);
    set_program_inner(right.program);
    this->languages_number = right.languages_number;
    set_languages_inner(right.languages);
}

void EUStudent:: delete_eustudent()
{
    delete [] eu_country;
    delete [] program;
    delete_languages();
    eu_country = NULL;
    program = NULL;
}

void EUStudent:: delete_languages()
{
    for(unsigned i = 0; i < languages_number; ++i)
    {
        delete [] languages[i];
        languages[i] = NULL;
    }
    delete [] languages;
    languages = NULL;
}

void EUStudent:: set_eucountry(const char* eucountry)
{
    delete [] this->eu_country;
    set_eucountry_inner(eucountry);
}

void EUStudent:: set_program(const char* program)
{
    delete [] this->program;
    set_program_inner(program);
}

void EUStudent:: set_languages(const char* const* languages, unsigned languages_number)
{
    delete_languages();
    this->languages_number = languages_number;
    set_languages_inner(languages);
}

void EUStudent:: set_eucountry_inner(const char* eucountry)
{
    this->eu_country = new char[strlen(eucountry) + 1];
    strcpy(this->eu_country, eucountry);
}

void EUStudent:: set_program_inner(const char* program)
{
    this->program = new char[strlen(program) + 1];
    strcpy(this->program, program);
}

void EUStudent:: set_languages_inner(const char* const* languages)
{
    this->languages = new char*[languages_number];
    for(unsigned i = 0; i < languages_number; ++i)
    {
        this->languages[i] = new char[strlen(languages[i]) + 1];
        strcpy(this->languages[i], languages[i]);
    }
}

const char* EUStudent:: get_eucountry()const
{
    return eu_country;
}

const char* EUStudent:: get_program()const
{
    return program;
}

const char*const * EUStudent:: get_languages()const
{
    return languages;
}
