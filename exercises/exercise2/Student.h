#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <cstring>

struct Student
{
	unsigned facNum;
	char name[41];
	double marks;

	void set_name(const char* _name);
	void set_marks(double _marks);
	void set_facNum(unsigned _facNum);
	void read();
	void print() const;
};
#endif // STUDENT_H_INCLUDED
