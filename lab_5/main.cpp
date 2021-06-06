#include <iostream>
#include "Stack.h"
#include "CircleList.h"

int main() {
	Stack s;
	s.push('c');
	s.push('c');
	s.push('c');
	s.push('b');
	s.push('d');
	s.push('a');
	s.sort();
	s.print();
	std::cout << std::endl;
	Stack s2;
	s2.push('z');
	s2.push('c');
	s2.push('x');
	s2.push('a');
	s2.push('a');
	s2.push('a');
	s2.sort();
	s2.print();
	std::cout << std::endl;
	CircleList l;
	l.insert(&s, 0);
	l.insert(&s2, 1);
	l.merge_stacks();
	l.start->stack->print();

}

