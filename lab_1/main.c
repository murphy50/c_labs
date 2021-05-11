#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#include <cstddef>
#include "computing.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int main() {

  // Ввод чисел
  printf("Enter the first number\n");
  int first_number;
  scanf("%d", &first_number);
  printf("Enter the second number\n");
  int second_number;
  scanf("%d", &second_number);
  
  size_t len_first = len(first_number);
  size_t len_second = len(second_number);
  if (len_first < len_second) {
    swap(&first_number, &second_number);
 }

  // Выделение памяти
  int* first_array = (int*)malloc(len_first * sizeof(int));
  int* second_array = (int*)malloc(len_second * sizeof(int));

  // Ввод элементов в массивы
  enter_digits_to_mas(first_array, first_number);
  enter_digits_to_mas(second_array, second_number);

  size_t margin = len_first + len_second;
  print_margin(margin);
  printf("%d\n", first_number);
  print_margin(margin);
  printf("%d\n", second_number);
  printf("**********************\n");

  for (size_t i = 0; i < len_second; ++i) {
    print_margin(margin);
    printf("%d\n", second_array[i] * first_number);
    --margin;
}

  printf("**********************\n");
  print_margin(margin);
  printf("%d", first_number * second_number);



  free(first_array);
  free(second_array);


  return 0;
}