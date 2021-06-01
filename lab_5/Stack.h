#ifndef STACK_H
#define STACK_H
class Stack {
public:
	struct StackNode {
		char value;
		StackNode* next;
		StackNode(int val) :value(val), next(nullptr) {}

	};
	StackNode* top;
	Stack();
	~Stack();
	bool empty();
	void pop();
	void push(char val);
	void sorted_insert(char val);
	void sort();
	void print();

};
#endif