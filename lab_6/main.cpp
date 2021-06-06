#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include "tree.cpp"
#include "tree.h"
int main()
{
	Tree<int> t1;
	t1.insert_node(20);
	t1.insert_node(10);
	t1.insert_node(50);
	t1.insert_node(8);
	t1.insert_node(3);
	t1.insert_node(9);
	t1.insert_node(40);
	t1.print();
	t1.delete_node(t1.find_succsessor(3));
	t1.print();
	std::cout << std::endl;
	Tree<int> t2;
	t2.insert_node(1);
	t2.insert_node(2);
	t2.insert_node(100);
	t2.insert_node(3);
	t2.insert_node(80);
	t2.insert_node(120);
	t2.print();
	std::cout << std::endl;
	Tree<int> t3;
	t3.root = t1.merge_trees(t2.root);
	t3.print();
	std::cout << std::endl;
	return 0;
}
