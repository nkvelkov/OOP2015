#include <iostream>
#include <cstring>
#include "Group.h"
using namespace std;

int main()
{
    Student student, student1, student2;

    student.read();
    student.print();

    student.set_facNum(12345);
    student.set_marks(5.5);
    student.print();

    student1.read();
    student2.read();

    Student students[100];
    students[0] = student;
    students[1] = student1;
    students[2] = student2;

    Group group(students, 3);

    group.print();
    group.studHighestGrades();
    group.print();

    return 0;
}
