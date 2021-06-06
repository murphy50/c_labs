#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "gaps.h"
#include "list.h"
#include <assert.h>

void TestXgaps(int*** a) {
    Node* list_x = Xgaps(a, 2);
    Node* tmp = list_x;
    assert(tmp->coordinates.z == 0 && tmp->coordinates.y == 0 && tmp->coordinates.x == 1);
    tmp = tmp->next;
    assert(tmp->coordinates.z == 0 && tmp->coordinates.y == 1 && tmp->coordinates.x == 1);
    tmp = tmp->next;
    assert(tmp->coordinates.z == 1 && tmp->coordinates.y == 0 && tmp->coordinates.x == 1);
    tmp = tmp->next;
    assert(tmp->coordinates.z == 1 && tmp->coordinates.y == 1 && tmp->coordinates.x == 1);
    DeleteList(list_x);
}

void TestYgaps(int*** a) {
    Node* list_y = Ygaps(a, 2);
    Node* tmp = list_y;
    assert(tmp->coordinates.z == 0 && tmp->coordinates.y == 1 && tmp->coordinates.x == 0);
    tmp = tmp->next;
    assert(tmp->coordinates.z == 0 && tmp->coordinates.y == 1 && tmp->coordinates.x == 1);
    tmp = tmp->next;
    assert(tmp->coordinates.z == 1 && tmp->coordinates.y == 1 && tmp->coordinates.x == 0);
    tmp = tmp->next;
    assert(tmp->coordinates.z == 1 && tmp->coordinates.y == 1 && tmp->coordinates.x == 1);
    DeleteList(list_y);
}

void TestZgaps(int*** a) {
    Node* list_z = Zgaps(a, 2);
    Node* tmp = list_z;
    assert(tmp->coordinates.z == 1 && tmp->coordinates.y == 0 && tmp->coordinates.x == 0);
    tmp = tmp->next;
    assert(tmp->coordinates.z == 1 && tmp->coordinates.y == 1 && tmp->coordinates.x == 0);
    tmp = tmp->next;
    assert(tmp->coordinates.z == 1 && tmp->coordinates.y == 0 && tmp->coordinates.x == 1);
    tmp = tmp->next;
    assert(tmp->coordinates.z == 1 && tmp->coordinates.y == 1 && tmp->coordinates.x == 1);
    DeleteList(list_z);
}

int main() {
    int n = 2;
    int*** a = (int***)malloc(n * sizeof(int**));
    for (int i = 0; i < n; i++) {
        a[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            a[i][j] = (int*)malloc(n * sizeof(int));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                a[i][j][k] = 0;
            }
        }
    }
    TestXgaps(a);
    TestYgaps(a);
    TestZgaps(a);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);

}