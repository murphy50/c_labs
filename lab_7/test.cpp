#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <cassert>
#include "workflow.h"

void TestUpdateList(std::ifstream& fin, std::list<Student>& Students) {
	assert(UpdateList(fin, Students) == true);
	std::ifstream error_fin;
	error_fin.open("wrong.txt");
	assert(UpdateList(error_fin, Students) == false);
}

void TestCheckInAll(std::list<Student>& Students, std::vector <std::map<int, std::string>>& floors) {
	assert(CheckInAll(Students, floors) == true);
}

void TestGetViolations(std::vector <std::map<int, std::string>>& floors, std::list<Student>& Students) {
	std::string tmp_name = "Alfonsooo";
	std::string tmp_surname = "Pierce";
	Student* tmp_stud = FindStudent(tmp_name, tmp_surname, Students);
	assert(tmp_stud == nullptr);
	tmp_name = "Alfonso";
	tmp_stud = FindStudent(tmp_name, tmp_surname, Students);
	assert(tmp_stud != nullptr);

	assert(GetViolations(*tmp_stud, floors) == true);
	assert(GetViolations(*tmp_stud, floors) == true);
	assert(GetViolations(*tmp_stud, floors) == false);
}

void TestPrintData(std::ofstream& fout, std::vector <std::map<int, std::string>>& floors) {
	PrintData(fout, floors);
}

void TestCheckIn(std::vector <std::map<int, std::string>>& floors, std::list<Student>& Students) {
	Student stud;
	stud.name = "John";
	stud.surname = "Johns";
	stud.faculty = "FACULTY_OF_RADIOENGINEERING_AND_ELECTRONICS";
	Students.push_back(stud);

	if (stud.faculty == "FACULTY_OF_RADIOENGINEERING_AND_ELECTRONICS") {
		stud.floor = 1;
		assert(CheckIn(floors[0], stud) == true);
	}
	else if (stud.faculty == "FACULTY_OF_INFOCOMMUNICATIONS") {
		stud.floor = 2;
		CheckIn(floors[1], stud);
	}
	else if (stud.faculty == "FACULTY_OF_ENGINEERING_AND_ECONOMICS") {
		stud.floor = 3;
		CheckIn(floors[2], stud);
	}
	else if (stud.faculty == "FACULTY_OF_COMPUTER_SYSTEMS_AND_NETWORKS") {
		stud.floor = 4;
		CheckIn(floors[3], stud);
	}

	Student stud2;
	stud2.name = "John2";
	stud2.surname = "Johns2";
	stud2.faculty = "FACULTY_OF_INFOCOMMUNICATIONS";
	Students.push_back(stud2);

	if (stud2.faculty == "FACULTY_OF_RADIOENGINEERING_AND_ELECTRONICS") {
		stud2.floor = 1;
		CheckIn(floors[0], stud2);
	}
	else if (stud2.faculty == "FACULTY_OF_INFOCOMMUNICATIONS") {
		stud2.floor = 2;
		assert(CheckIn(floors[1], stud2) == true);
	}
	else if (stud2.faculty == "FACULTY_OF_ENGINEERING_AND_ECONOMICS") {
		stud2.floor = 3;
		CheckIn(floors[2], stud2);
	}
	else if (stud2.faculty == "FACULTY_OF_COMPUTER_SYSTEMS_AND_NETWORKS") {
		stud2.floor = 4;
		CheckIn(floors[3], stud2);
	}

	Student stud3;
	stud3.name = "John3";
	stud3.surname = "Johns3";
	stud3.faculty = "FACULTY_OF_ENGINEERING_AND_ECONOMICS";
	Students.push_back(stud3);

	if (stud3.faculty == "FACULTY_OF_RADIOENGINEERING_AND_ELECTRONICS") {
		stud3.floor = 1;
		CheckIn(floors[0], stud3);
	}
	else if (stud3.faculty == "FACULTY_OF_INFOCOMMUNICATIONS") {
		stud3.floor = 2;
		CheckIn(floors[1], stud3);
	}
	else if (stud3.faculty == "FACULTY_OF_ENGINEERING_AND_ECONOMICS") {
		stud3.floor = 3;
		assert(CheckIn(floors[2], stud3) == true);
	}
	else if (stud3.faculty == "FACULTY_OF_COMPUTER_SYSTEMS_AND_NETWORKS") {
		stud3.floor = 4;
		CheckIn(floors[3], stud3);
	}

	Student stud4;
	stud4.name = "John4";
	stud4.surname = "Johns4";
	stud4.faculty = "FACULTY_OF_COMPUTER_SYSTEMS_AND_NETWORKS";
	Students.push_back(stud4);
	if (stud4.faculty == "FACULTY_OF_RADIOENGINEERING_AND_ELECTRONICS") {
		stud4.floor = 1;
		CheckIn(floors[0], stud4);
	}
	else if (stud4.faculty == "FACULTY_OF_INFOCOMMUNICATIONS") {
		stud4.floor = 2;
		CheckIn(floors[1], stud4);
	}
	else if (stud4.faculty == "FACULTY_OF_ENGINEERING_AND_ECONOMICS") {
		stud4.floor = 3;
		CheckIn(floors[2], stud4);
	}
	else if (stud4.faculty == "FACULTY_OF_COMPUTER_SYSTEMS_AND_NETWORKS") {
		stud4.floor = 4;
		assert(CheckIn(floors[3], stud4) == false);
	}
}

int main()
{
	std::ofstream fout;
	std::ifstream fin;
	fin.open("input.txt");
	fout.open("output.txt");
	if (fin.fail()) {
		std::cout << "error";
		return 1;
	}
	fout.open("output.txt");
	if (fin.fail()) {
		std::cout << "error";
		return 1;
	}
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
	TestUpdateList(fin, Students);
	TestCheckInAll(Students, DormitoryFloors);
	TestGetViolations(DormitoryFloors, Students);
	TestPrintData(fout, DormitoryFloors);
	TestCheckIn(DormitoryFloors, Students);
	Options();


	Student student11;
	fin >> student11;
	fout << student11;
	assert(student11 == student11);

	fin.close();
	fout.close();
	return 0;
}
