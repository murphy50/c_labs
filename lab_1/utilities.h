#ifndef UTILITIES_H
#define UTILITIES_H

void Swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int Len(int n) {
  if(n==0){
      return 1;
  }
  int count = 0;
  while (n != 0) {
    count++;
    n /= 10;
  }
  return count;
}

// Заполнение массива цифрами
void EnterDigitsToArray(int* n, int number) {
  for (int i = 0; number != 0; ++i)
  {
    n[i] = number % 10;
    number /= 10;
  }
}

// Расчет ширины поля(отступ)
void PrintMargin(int margin) {
  for (int i = 0; i < margin; ++i) {
    printf(" ");
  }
}
#endif 