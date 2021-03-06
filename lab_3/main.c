#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include "gaps.h"
#include "list.h"

int main() {
    srand((unsigned)time(NULL));
    int n;
    printf("Enter n: \n");
    if (scanf("%d", &n) == 0) {
        return 0;
    }
    // Выделение памяти
    int*** a = (int***)malloc(n * sizeof(int**));
    if (a == NULL) {
        printf("Can't allocate memory\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        a[i] = (int**)malloc(n * sizeof(int*));
        if (a[i] == NULL) {
            for (int j = i - 1; j >= 0; j--) {
                free(a[j]);
            }
            free(a);
            printf("Can't allocate memory\n");
            return 1;
        }
        for (int j = 0; j < n; j++) {
            a[i][j] = (int*)malloc(n * sizeof(int));
            if (a[i][j] == NULL) {
                for (int f = 0; f < n; f++) {
                    for (int k = j - 1; k >= 0; k--) {
                        free(a[f][k]);
                    }
                }
                free(a);
                printf("Can't allocate memory\n");
                return 1;
            }
        }
    }

    // Ввод элементов массива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                a[i][j][k] = rand() % 2;
            }
        }
    }

    // вывод просветов
    printf("coordinates of the gaps along the axis 0X:\nz y x1 - z y x2 \n");
    Node* list_x = Xgaps(a, n);
    Node* tmp = list_x;
    for (int i = 0; tmp; ++i) {
        printf("%d %d %d -- %d %d %d\n", tmp->coordinates.z, tmp->coordinates.y, 0,
            tmp->coordinates.z, tmp->coordinates.y, tmp->coordinates.x);
        tmp = tmp->next;
    }
    DeleteList(list_x);

    printf("\n");
    printf("coordinates of the gaps along the axis 0Y:\nz y1 x - z y2 x \n");
    Node* list_y = Ygaps(a, n);
    tmp = list_y;
    for (int i = 0; tmp; ++i) {
        printf("%d %d %d -- %d %d %d\n", tmp->coordinates.z, 0, tmp->coordinates.x,
            tmp->coordinates.z, tmp->coordinates.y, tmp->coordinates.x);
        tmp = tmp->next;
    }
    DeleteList(list_y);

    printf("\n");
    printf("coordinates of the gaps along the axis 0Z:\nz1 y x - z2 y x \n");
    Node* list_z = Zgaps(a, n);
    tmp = list_z;
    for (int i = 0; tmp; ++i) {
        printf("%d %d %d -- %d %d %d\n", 0, tmp->coordinates.y, tmp->coordinates.x,
            tmp->coordinates.z, tmp->coordinates.y, tmp->coordinates.x);
        tmp = tmp->next;
    }
    DeleteList(list_z);
    printf("\n");

    //вывод
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("%d ", a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    //очистка памяти
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);

    return 0;
}