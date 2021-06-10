#ifndef WORKFLOW_H
#define WORKFLOW_H
#include "Student.h"
//check in student
bool CheckIn(std::map<int, std::string>& floor, Student& stud);

bool GetViolations(Student& stud, std::vector<std::map<int, std::string>>& floors);
// students from txt file to list
bool UpdateList(std::ifstream& fin, std::list<Student>& Students);

void PrintData(std::ofstream& fout, std::vector<std::map<int, std::string>>& floors);
// accommodation of students in rooms
bool CheckInAll(std::list<Student>& Students, std::vector<std::map<int, std::string>>& floors);

void Options();

Student* FindStudent(std::string& name, std::string& surname, std::list<Student>& Students);

#endif