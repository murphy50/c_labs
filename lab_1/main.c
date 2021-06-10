#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "utilities.h"
int main()
{

  // Ввод чисел
  printf("Enter the first number\n");
  int first_number;
  if (!scanf("%d", &first_number))
  {
    printf("error\n");
    return 1;
  };
  printf("Enter the second number\n");
  int second_number;
  if (!scanf("%d", &second_number))
  {
    printf("error\n");
    return 1;
  };

  int len_first = Len(first_number);
  int len_second = Len(second_number);
  if (len_first < len_second)
  {
    Swap(&first_number, &second_number);
  }

  // Выделение памяти
  int *first_array = (int *)malloc(len_first * sizeof(int));
  if (first_array == NULL)
  {
    printf("Can't allocate memory\n");
    return 1;
  }
  int *second_array = (int *)malloc(len_second * sizeof(int));
  if (second_array == NULL)
  {
    printf("Can't allocate memory\n");
    return 1;
  }

  // Ввод элементов в массивы
  EnterDigitsToArray(first_array, first_number);
  EnterDigitsToArray(second_array, second_number);

  int margin = len_first + len_second;
  PrintMargin(margin);
  printf("%d\n", first_number);
  PrintMargin(margin);
  printf("%d\n", second_number);
  printf("**********************\n");

  for (int i = 0; i < len_second; ++i)
  {
    PrintMargin(margin);
    printf("%d\n", second_array[i] * first_number);
    --margin;
  }

  printf("**********************\n");
  PrintMargin(margin);
  printf("%d", first_number * second_number);

  free(first_array);
  free(second_array);
  return 0;
}