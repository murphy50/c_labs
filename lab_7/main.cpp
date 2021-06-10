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
	std::ifstream action;
	fin.open("input.txt");
	fout.open("output.txt");
	action.open("InputActions");
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
	while (Menu(action, fin, fout, Students, DormitoryFloors)) {
	}
	action.close();
	fin.close();
	fout.close();
	return 0;
}
