#include "Student.h"
#include <iostream>

using namespace std;

void Student:: set_name(const char* _name)
{
        strcpy(name, _name);
}

void Student:: set_marks(double _marks)
{
    if(_marks < 2 || _marks > 6)
    {
        cout << "Marks given incorrect. Setting default value - 2.\n";
        marks = 2;
    }
    else
    {
        marks = _marks;
    }
}

void Student:: set_facNum(unsigned _facNum)
{
    facNum = _facNum;
}

void Student:: read()
{
    cout << "Enter the name of the student : ";
    cin.getline(name, 41);

    do
    {
        cout << "Enter the facult number of the student : ";
        cin >> facNum;
    }while(facNum < 0);

    do
    {
        cout << "Enter the average marks of the student : ";
        cin >> marks;
    }while(marks < 2 || marks > 6);

    cin.get(); //Cleans the buffer from the cin function
}

void Student:: print() const
{
    cout << "Name : " << name << endl
         << "Facult number : " << facNum << endl
         << "Marks : " << marks << "\n\n";
}
