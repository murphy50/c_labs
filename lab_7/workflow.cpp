#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include "workflow.h"

//check in student
bool CheckIn(std::map<int, std::string>& floor, Student& stud) {
	for (auto& now : floor) {
		if (now.second == "free") {
			now.second = stud.name + " " + stud.surname + " " + stud.faculty + " " + std::to_string(stud.violations);
			stud.room = now.first;
			return true;
		}
	}
	std::cout << "no rooms available" << std::endl;
	return false;
}
bool GetViolations(Student& stud, std::vector <std::map<int, std::string>>& floors) {
	++stud.violations;
	if (stud.violations == 3) {
		std::cout << "This student has 3 violations he is evicted from the dormitory" << std::endl;
		floors[(stud.room / 10) - 1].erase(stud.room);
		stud.room = 0;
		return false;
	}
	else {
		std::cout << "violations successfully assigned" << std::endl;
		return true;
	}

}
// students from txt file to list
bool UpdateList(std::ifstream& fin, std::list<Student>& Students) {
	//check
	if (!fin) {
		std::cerr << "Uh oh, SomeText.txt could not be opened for reading!" << std::endl;
		return false;
	}
	for (Student st; fin >> st; Students.push_back(st)) {
	}
	std::cout << "The list of students has been updated" << std::endl;
	return true;
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
bool CheckInAll(std::list<Student>& Students, std::vector <std::map<int, std::string>>& floors) {
	bool flag = 0;
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
			return false;
		}
	}
	return true;
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