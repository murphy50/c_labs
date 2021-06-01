#ifndef CIRCLE_LIST_H
#define CIRCLE_LIST_H
#include"Stack.h"
class CircleList : Stack {
private:
	struct ListNode {

		ListNode* next;
		ListNode* prev;
		Stack* stack;
		ListNode(Stack* stk) : next(this), prev(this), stack(stk) {}
	};
public:
	ListNode* start;
	size_t size;
	CircleList() : start(nullptr), size(0) {}
	~CircleList() {

	}
	void insert(Stack* stk, int pos);
	void erase(int pos);
	void erase_node(ListNode* node);
	size_t get_size();
	ListNode* merge_stacks();

};
#endif