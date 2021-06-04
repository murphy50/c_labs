#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Coordinates {
	int z;
	int y;
	int x;
} Coordinates;

typedef struct Node {
	struct Node* next;
	struct Node* prev;
	Coordinates coordinates;
} Node;

void PushBack(Node** head,Node** tail, Coordinates* coord) {
	if (*head == NULL) {
		Node* elem = (Node*)malloc(sizeof(Node));
		elem->coordinates = *coord;
		elem->next = NULL;
		elem->prev = *tail;
		*tail = elem;
		*head = elem;
		return;
	}
	Node* elem = (Node*)malloc(sizeof(Node));
	elem->coordinates = *coord;
	elem->next = NULL;
	elem->prev = *tail;
	(*tail)->next= elem;
	*tail = elem;
	return;
}

void DeleteList(Node* head) {	
	while (head) {
		Node* tmp = head;
		head = head->next;
		free(tmp);
	}
}
#endif