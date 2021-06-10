#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include "workflow.h"

int main()
{
	std::ofstream fout;
	std::ifstream fin;
	fin.open("input.txt");
	fout.open("output.txt");
	if (!fin) {
		std::cerr << "Uh oh, input.txt could not be opened for reading!" << std::endl;
		return 1;
	}
	if (!fout) {
		std::cerr << "Uh oh, output.txt could not be opened for reading!" << std::endl;
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

	int answer = 1;
	while (answer == 1) {
		Options();
		int number;
		std::cout << "Enter the number" << std::endl;
		std::cin >> number;
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
			std::cout << "Enter name and surname" << std::endl;
			std::cin >> tmp_name >> tmp_surname;
			Student* tmp_stud = FindStudent(tmp_name, tmp_surname, Students);
			if (FindStudent(tmp_name, tmp_surname, Students) == nullptr) {
				std::cout << "The student was not found" << std::endl;
				break;
			}
			GetViolations(*tmp_stud, DormitoryFloors);
			break;
		}
		case 4: {
			PrintData(fout, DormitoryFloors);
			break;
		}
		case 5: {
			Student stud;
			std::cout << "Enter name, surname, faculty" << std::endl;
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
				break;
			}
			break;
		}
		case 6: {
			std::string tmp_name, tmp_surname;
			std::cout << "Enter name and surname" << std::endl;
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
			std::cout << ("Option not selected") << std::endl;
		}
		std::cout << "Would you like to continue? enter - 1 to continue" << std::endl;
		std::cin >> answer;
	}

	fin.close();
	fout.close();
	return 0;
}
