#ifndef STUDENT_H
#define STUDENT_H
struct Student {
	std::string name;
	std::string surname;
	std::string faculty;
	int room;
	int floor;
	int violations;
	Student();
	friend std::ostream& operator<< (std::ostream& out, const Student& student);
	friend std::istream& operator>> (std::istream& in, Student& student);
	friend bool operator== (const Student& stud1, const Student& stud2);
};
#endif