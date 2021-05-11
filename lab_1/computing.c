#include <stdio.h>
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

size_t len(int n) {
  if(n==0){
      return 1;
  }
  size_t count = 0;
  while (n != 0) {
    count++;
    n /= 10;
  }
  return count;
}

// Заполнение массива цифрами
void enter_digits_to_mas(int* n, int number) {
  for (size_t i = 0; number != 0; ++i)
  {
    n[i] = number % 10;
    number /= 10;
  }
}

// Расчет ширины поля(отступ)
void print_margin(const size_t margin) {
  for (int i = 0; i < margin; ++i) {
    printf(" ");
  }
}

