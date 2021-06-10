#ifndef WORKFLOW_H
#define WORKFLOW_H
#include "Student.h"
//check in student
void CheckIn(std::map<int, std::string>& floor, Student& stud);

void GetViolations(Student& stud, std::vector<std::map<int, std::string>>& floors);
// students from txt file to list
void UpdateList(std::ifstream& fin, std::list<Student>& Students);

void PrintData(std::ofstream& fout, std::vector<std::map<int, std::string>>& floors);
// accommodation of students in rooms
void CheckInAll(std::list<Student>& Students, std::vector<std::map<int, std::string>>& floors);

void Options();

Student* FindStudent(std::string& name, std::string& surname, std::list<Student>& Students);
// some set of functions for user 
bool Menu(std::ifstream& fin, std::ofstream& fout, std::list<Student>& Students, std::vector<std::map<int, std::string>>& DormitoryFloors);

#endif