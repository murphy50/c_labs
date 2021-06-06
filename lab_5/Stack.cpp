#include "iostream"
#include "Stack.h"
Stack::Stack() : top(nullptr) {}
Stack::~Stack() {
	while (!empty()) {
		pop();
	}
}

bool Stack::empty()
{
	return (top == nullptr);
}

void Stack::pop() {
	if (top == nullptr) {
		return;
	}
	StackNode* tmp = top;
	top = top->next;
	delete(tmp);

}

void Stack::push(char val) {
	StackNode* elem = new StackNode(val);
	elem->next = top;
	top = elem;
}

void Stack::sorted_insert(char val) {// рекурсиваная вставка
	if (top == nullptr) {
		push(val);
		return;
	}
	if (val >= (top->value)) {
		push(val);
		return;
	}
	//если вершина больше, удаляем вершину и вставляем
	char tmp = top->value;
	pop();
	sorted_insert(val);
	push(tmp);
}

void Stack::sort() {
	if (!empty()) {
		char tmp = top->value;
		pop();
		sort();
		sorted_insert(tmp);
	}
}

void Stack::print() {
	StackNode* tmp = top;
	while (tmp) {

		std::cout << tmp->value << std::endl;
		tmp = tmp->next;
	}
}