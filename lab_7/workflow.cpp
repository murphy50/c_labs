#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include "workflow.h"

//check in student
void CheckIn(std::map<int, std::string>& floor, Student& stud) {
	for (auto& now : floor) {
		if (now.second == "free") {
			now.second = stud.name + " " + stud.surname + " " + stud.faculty + " " + std::to_string(stud.violations);
			stud.room = now.first;
			return;
		}
	}
}
void GetViolations(Student& stud, std::vector <std::map<int, std::string>>& floors) {
	++stud.violations;
	if (stud.violations == 3) {
		std::cout << "This student has 3 violations he is evicted from the dormitory" << std::endl;
		floors[(stud.room / 10) - 1].erase(stud.room);
		stud.room = 0;
	}
	else {
		std::cout << "violations successfully assigned" << std::endl;
	}
}
// students from txt file to list
void UpdateList(std::ifstream& fin, std::list<Student>& Students) {
	//check
	if (!fin) {
		std::cerr << "Uh oh, SomeText.txt could not be opened for reading!" << std::endl;
		exit(1);
	}
	for (Student st; fin >> st; Students.push_back(st)) {
	}
	std::cout << "The list of students has been updated" << std::endl;
}

void PrintData(std::ofstream& fout, std::vector <std::map<int, std::string>>& floors) {
	for (auto& now : floors) {
		for (auto& now2 : now) {
			fout << now2.first << " = " << now2.second << std::endl;
		}
		fout << std::endl;
	}
	fout << std::endl << std::endl;
}
// accommodation of students in rooms
void CheckInAll(std::list<Student>& Students, std::vector <std::map<int, std::string>>& floors) {
	for (auto& stud : Students) {
		if (stud.faculty == "FACULTY_OF_RADIOENGINEERING_AND_ELECTRONICS") {
			stud.floor = 1;
			CheckIn(floors[0], stud);
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
		else {
			std::cout << "faculty not found" << std::endl;
			exit(1);
		}
	}
}
// some set of functions for user 
void Options() {
	std::cout << "To select an operation, enter a number:" << std::endl;
	std::cout << "1: Update the list of students from txt" << std::endl;
	std::cout << "2: Move students into the dormitory" << std::endl;
	std::cout << "3: Give a violation" << std::endl;
	std::cout << "4: Print the list of residents to txt" << std::endl;
	std::cout << "5: Add a resident" << std::endl;
	std::cout << "6: Delete a resident" << std::endl;
}

Student* FindStudent(std::string& name, std::string& surname, std::list<Student>& Students) {
	for (auto& now : Students) {
		if (now.name == name && now.surname == surname) {
			return &now;
		}
	}
	return nullptr;
}

bool Menu(std::ifstream& action, std::ifstream& fin, std::ofstream& fout, std::list<Student>& Students, std::vector <std::map<int, std::string>>& DormitoryFloors) {
	Options();
	int number;
	action >> number;
	switch (number) {
	case 1: {
		UpdateList(fin, Students);
		break;
	}
	case 2: {
		CheckInAll(Students, DormitoryFloors);
		break;
	}
	case 3: {
		std::string tmp_name, tmp_surname;
		action >> tmp_name >> tmp_surname;
		Student* tmp_stud = FindStudent(tmp_name, tmp_surname, Students);
		GetViolations(*tmp_stud, DormitoryFloors);
		break;
	}
	case 4: {
		PrintData(fout, DormitoryFloors);
		break;
	}
	case 5: {
		Student stud;
		std::cin >> stud.name >> stud.surname >> stud.faculty;
		Students.push_back(stud);

		if (stud.faculty == "FACULTY_OF_RADIOENGINEERING_AND_ELECTRONICS") {
			stud.floor = 1;
			CheckIn(DormitoryFloors[0], stud);
		}
		else if (stud.faculty == "FACULTY_OF_INFOCOMMUNICATIONS") {
			stud.floor = 2;
			CheckIn(DormitoryFloors[1], stud);
		}
		else if (stud.faculty == "FACULTY_OF_ENGINEERING_AND_ECONOMICS") {
			stud.floor = 3;
			CheckIn(DormitoryFloors[2], stud);
		}
		else if (stud.faculty == "FACULTY_OF_COMPUTER_SYSTEMS_AND_NETWORKS") {
			stud.floor = 4;
			CheckIn(DormitoryFloors[3], stud);
		}
		else {
			std::cout << "faculty not found" << std::endl;
			exit(1);
		}
		break;
	}
	case 6: {
		std::string tmp_name, tmp_surname;
		std::cin >> tmp_name >> tmp_surname;
		Student tmp_stud = *FindStudent(tmp_name, tmp_surname, Students);
		Students.remove(tmp_stud);
		if (DormitoryFloors[tmp_stud.floor - 1].count(tmp_stud.room)) {
			DormitoryFloors[tmp_stud.floor - 1].erase(tmp_stud.room);
		}
		else {
			fout << "Student not found" << std::endl;
		}
		break;
	}
	default:
		printf("Option not selected\n");
	}
	int answer;
	action >> answer;
	if (answer == 1) {
		return 1;
	}
	else {
		return 0;
	}
}


