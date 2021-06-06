#include <stdio.h>
#include <math.h>
#include "calculation.h"
int main()
{
  double arg;
  double inaccuracy;
  printf("enter argument and inaccuracy\n");
  if(!scanf("%lf %lf\n", &arg, &inaccuracy)){
    return 1;
  }
  printf("%d", Calculation(arg, inaccuracy));

  return 0;
}
