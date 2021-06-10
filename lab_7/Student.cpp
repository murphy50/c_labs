#include <iostream>
#include <fstream>
#include "Student.h"

Student::Student() : name("noname"), surname("nosurname"), faculty("nofaculty"), room(0), floor(0), violations(0) {}

std::ostream& operator<< (std::ostream& out, const Student& student) {
	out << student.name << " " << student.surname << " " << student.faculty << " floor:" << student.floor << " room:" << student.room << " violations:" << student.violations;
	return out;
}

std::istream& operator>> (std::istream& in, Student& student) {
	in >> student.name;
	in >> student.surname;
	in >> student.faculty;
	return in;
}

bool operator== (const Student& stud1, const Student& stud2)
{
	return (stud1.name == stud2.name &&
		stud2.surname == stud2.surname);
}