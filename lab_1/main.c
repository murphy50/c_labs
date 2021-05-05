#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#include "swap.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int len(int n) {
  int count = 0;
  while (n != 0) {
    count++;
    n /= 10;
  }
  return count;
}
// Заполнение массива цифрами
void enter_digits_to_mas(int* n, int digit) {
  for (int i = 0; digit != 0; i++)
  {
    n[i] = digit % 10;
    digit /= 10;
  }
}

// Расчет ширины поля(отступ)
void print_margin(int margin) {
  for (int i = 0; i < margin; i++) {
    printf(" ");
  }
}


int main() {
  // Ввод чисел
  printf("Enter the first number\n");
  int first_number;
  scanf("%d", &first_number);
  printf("Enter the second number\n");
  int second_number;
  scanf("%d", &second_number);

  if (len(first_number) < len(second_number)) {
    swap(&first_number, &second_number);
 }

  // Выделение памяти
  int* first_array = (int*)malloc((len(first_number) + 1) * sizeof(int));
  int* second_array = (int*)malloc((len(second_number) + 1) * sizeof(int));

  // Ввод элементов массива
  enter_digits_to_mas(first_array, first_number);
  enter_digits_to_mas(second_array, second_number);

  int margin = len(second_number) + len(first_number);
  print_margin(margin + 1);
  printf("%d\n", first_number);
  print_margin(margin + 1);
  printf("%d\n", second_number);
  printf("**********************\n");

  for (int i = 0; i < len(second_number); i++) {
    print_margin(margin);
    printf("%d\n", second_array[i] * first_);
    --margin;
}

  printf("**********************\n");
  print_margin(margin - 1);
  printf("%d", first_number * second_number);



  free(first_array);
  free(second_array);


  return 0;
}