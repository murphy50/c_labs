#include <iostream>
#include "CircleList.h"
#include"Stack.h"
void CircleList::insert(Stack* stk, int pos) {
	if (start == nullptr) {
		ListNode* elem = new ListNode(stk);
		start = elem;
		++size;
		return;
	}
	ListNode* tmp = start;
	for (size_t i = 0; i < pos; ++i) {
		tmp = tmp->next;
	}
	ListNode* elem = new ListNode(stk);
	elem->next = tmp->next;
	elem->prev = tmp;
	tmp->next->prev = elem;
	tmp->next = elem;
	++size;
	return;
}
void CircleList::erase(int pos) {
	if (start == nullptr) {
		return;
	}
	ListNode* tmp = start;
	for (size_t i = 0; i < pos; ++i) {
		tmp = tmp->next;
	}
	if (tmp == start) {
		start = tmp->next;
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	delete(tmp);
	--size;
}

void CircleList::erase_node(ListNode* node) {
	if (start == nullptr) {
		return;
	}
	if (node == start) {
		start = node->next;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete(node);
	--size;
}

size_t CircleList::get_size() {
	return size;
}

CircleList::ListNode* CircleList::merge_stacks()
{
	for (ListNode* temp_list = start->next; temp_list != start; temp_list = temp_list->next, erase_node(temp_list->prev)) {
		for (StackNode* temp_top = temp_list->stack->top; temp_top != nullptr; temp_top = temp_top->next) {
			start->stack->sorted_insert(temp_top->value);
		}
		temp_list->stack->~Stack();
	}
	return start;
}