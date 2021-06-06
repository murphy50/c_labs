#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "program.h"

 const struct Parameters test1 = {1, 0, 0};
 const struct Parameters test2 = {10, 20, 30};
 const struct Parameters test3 = {1000, 1000, 50};
 const struct Parameters test4 = {150, 300, 12};

void test_calculation()
{
    assert(strcmp(calculation(test1),tariffs[0].name)==0);
    assert(strcmp(calculation(test4),tariffs[2].name)==0);
    assert(strcmp(calculation(test2),tariffs[3].name)==0);
    assert(strcmp(calculation(test3),tariffs[3].name)==0);
    return;
}
int main(){
    test_calculation();
    return 0;
}