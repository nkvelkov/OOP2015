#include "Group.h"
#include <iostream>

using namespace std;

Group:: Group(const Student* _students, short _groupSize)
{
    for(int i = 0 ; i< _groupSize ; i++)
    {
        students[i] = _students[i];
    }
    groupSize = _groupSize;
}

double Group::averageMarks() const
{
	int result = 0;
	for(int i = 0; i < groupSize ; i++)
	{
		result += students[i].marks;
	}

	return result/groupSize;
}

void Group::print() const
{
	cout << "\t--- The group consists of : ---\n\n";
	for(int i = 0 ; i < groupSize ; i++)
	{
		students[i].print();
	}
	cout << endl;
}

void Group::studentByFacNum(unsigned _facNum) const
{
	for(int i = 0 ; i<groupSize ; i++)
	{
		if(students[i].facNum == _facNum)
		{
			students[i].print();
			return; // quits the function
		}
	}
	cout << "Error.Student not found.\n"; // printed if facult number isn't found
}

void Group::studLowestGrades() const
{
    Student worstStudent(students[0]);
	for(int i = 0 ; i<groupSize	 ; i++)
	{
		if(worstStudent.marks > students[i].marks)
			worstStudent = students[i];
	}
	worstStudent.print();
}

void Group::studHighestGrades() const
{
	Student bestStudent(students[0]);
	for(int i = 0 ; i<groupSize	 ; i++)
	{
		if(bestStudent.marks < students[i].marks)
			bestStudent = students[i];
	}
	bestStudent.print();
}

void Group::sortStudents()
{
	char choise;
	do
	{
		cout << "Choose sorting field\n"
			 << "1) f - sort by facult number\n"
			 << "2) m - sort by marks";
		cin >> choise;
	}while(choise != 'f' && choise != 'm');
	choise == 'f' ? sortStudByFacNum():sortStudByMarks();
}

void Group::sortStudByFacNum()
{
	int j;
	Student tempStudent;
	for(int i = 1 ; i < groupSize ; i++)
	{
		tempStudent = students[i];
		for(j = i ; j>0 && tempStudent.facNum>students[j-1].facNum ; j--)
			students[j] = students[j-1];
		students[j] = tempStudent;
	}
}

void Group::sortStudByMarks()
{
	int j;
	Student tempStudent;
	for(int i = 1 ; i < groupSize ; i++)
	{
		tempStudent = students[i];
		for(j = i ; j>0 && tempStudent.marks>students[j-1].marks ; j--)
			students[j] = students[j-1];
		students[j] = tempStudent;
	}
}
