#ifndef GAPS_H
#define GAPS_H
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* Xgaps(int*** a, int n) {
    Node* head = NULL;
    Node* tail = NULL;
    int i = 0;
    for (int z = 0; z < n; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (a[z][y][x] != 0) {
                    break;
                }
                if (x == n - 1) {
                    Coordinates coord = { z, y, x };
                    PushBack(&head, &tail, &coord);
                }
            }
        }
    }
    return head;
}

Node* Ygaps(int*** a, int n) {
    Node* head = NULL;
    Node* tail = NULL;
    int i = 0;
    for (int z = 0; z < n; z++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (a[z][y][x] != 0) {
                    break;
                }
                if (y == n - 1) {
                    Coordinates coord = { z, y, x };
                    PushBack(&head, &tail, &coord);
                }
            }
        }
    }
    return head;
}

Node* Zgaps(int*** a, int n) {
    Node* head = NULL;
    Node* tail = NULL;
    int i = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                if (a[z][y][x] != 0) {
                    break;
                }
                if (z == n - 1) {
                    Coordinates coord = { z, y, x };
                    PushBack(&head, &tail, &coord);
                }
            }
        }
    }
    return head;
}
#endif