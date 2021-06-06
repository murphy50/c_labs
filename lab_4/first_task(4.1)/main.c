#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "IsPeriodic.h"

int main()
{
  int n;
  printf("enter n:\n");
  if(!scanf("%d", &n)){
    printf("error");
    return 1;
  }
  getchar();
  char* arr = (char*)malloc(n * sizeof(char));
  printf("enter string:\n");
  for (int i = 0; i < n; i++)
  {
    if(!scanf("%c", &arr[i])){
      printf("error");
      return 1;
    }
  }
  arr[n] = '\0';
  if (IsPeriodic(arr))
    printf("Periodic");
  else 
    printf("not Periodic");
  free(arr);
  return 0;
}