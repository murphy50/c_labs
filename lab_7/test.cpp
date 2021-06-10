#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <cassert>
#include "workflow.h"

void TestGetViolations(std::vector <std::map<int, std::string>>& floors, std::list<Student>& studs) {
	std::string tmp_name = "Alfonso";
	std::string tmp_surname = "Pierce";
	Student* tmp_stud = FindStudent(tmp_name, tmp_surname, studs);
	GetViolations(*tmp_stud, floors);
	assert(tmp_stud->violations == 1);
	std::string tmp_name2 = "Gianna";
	std::string tmp_surname2 = "Davis";
	Student* tmp_stud2 = FindStudent(tmp_name2, tmp_surname2, studs);
	GetViolations(*tmp_stud2, floors);
	assert(tmp_stud2->violations == 1);
	GetViolations(*tmp_stud2, floors);
	GetViolations(*tmp_stud2, floors);
	assert(tmp_stud2->violations == 3);
	assert(tmp_stud == tmp_stud);
}

void TesFindStudent(std::list<Student>& studs) {
	std::string tmp_name = "Alfonso";
	std::string tmp_surname = "Pierce";
	assert(FindStudent(tmp_name, tmp_surname, studs) != nullptr);
	std::string tmp_name2 = "Gianna";
	std::string tmp_surname2 = "Davis";
	assert(FindStudent(tmp_name2, tmp_surname2, studs) != nullptr);
}

void TestCheckIn(std::vector <std::map<int, std::string>>& floors, std::list<Student>& studs) {
	Student st1;
	st1.name = "Alfonso";
	st1.surname = "Pierce";
	st1.faculty = "FACULTY_OF_ENGINEERING_AND_ECONOMICS";
	CheckIn(floors[2], st1);
	studs.push_back(st1);
	Student st2;
	st2.name = "Gianna";
	st2.surname = "Davis";
	st2.faculty = "FACULTY_OF_ENGINEERING_AND_ECONOMICS";
	CheckIn(floors[2], st2);
	studs.push_back(st2);
	Student st3;
	st3.name = "Johnathon";
	st3.surname = "Holmes";
	st3.faculty = "FACULTY_OF_ENGINEERING_AND_ECONOMICS";
	CheckIn(floors[2], st3);
	studs.push_back(st3);
	Student st4;
	st4.name = "Brian";
	st4.surname = "Pearson";
	st4.faculty = "FACULTY_OF_ENGINEERING_AND_ECONOMICS";
	CheckIn(floors[2], st4);
	studs.push_back(st4);
	assert(floors[2].size() == 4);


}

int main()
{
	std::ofstream fout;
	std::ifstream fin;
	fin.open("TestInput.txt");
	fout.open("TestOutput.txt");
	std::list<Student> Students;
	std::vector <std::map<int, std::string>> DormitoryFloors(4);
	// Initialization rooms
	for (size_t i = 0; i < DormitoryFloors.size(); ++i) {
		std::pair<int, std::string> room;
		DormitoryFloors[0].insert(room = { i + 10 ,"free" });
		DormitoryFloors[1].insert(room = { i + 20 ,"free" });
		DormitoryFloors[2].insert(room = { i + 30 ,"free" });
		DormitoryFloors[3].insert(room = { i + 40 ,"free" });
	}
	TestCheckIn(DormitoryFloors, Students);
	TestGetViolations(DormitoryFloors, Students);
	TesFindStudent(Students);
	Options();
	
	Student student11;
	fin >> student11;
	fout << student11;
	fin.close();
	fout.close();
	return 0;
}