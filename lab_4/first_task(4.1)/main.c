#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "isPeriodic.h"

int main()
{
  int n;
  printf("enter n:\n");
  scanf("%d", &n);
  getchar();
  char* arr = (char*)malloc(n * sizeof(char));
  printf("enter string:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%c", &arr[i]);
  }
  arr[n] = '\0';
  if (IsPeriodic(arr))
    printf("Periodic");
  else 
    printf("not Periodic");
  free(arr);
  return 0;
}