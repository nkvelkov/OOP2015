#ifndef GROUP_H_INCLUDED
#define GROUP_H_INCLUDED

#include "Student.h"

class Group
{
public:
	Group(const Student* students, short groupSize);

	void sortStudents(); // Sorts the students by the choosen field
	void sortStudByFacNum(); // function for sorting
	void sortStudByMarks();	 // function for sorting

  //--- Get Functions ---
	void studHighestGrades() const;
	void studLowestGrades() const;
	void studentByFacNum(unsigned _facNum) const;
	void print() const;
	double averageMarks() const;

	short getGroupSize() const { return groupSize; }
	const Student* getStudents() const { return students; }
  //--- End Get Functions ---

private:
	Student students[30];
	short groupSize;
};

#endif // GROUP_H_INCLUDED
