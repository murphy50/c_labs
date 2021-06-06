#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculation.h"

void test_calculation()
{
    assert(Calculation(0.34, 0.00000001) == 4);
    assert(Calculation(0.34, 0.000000000000001) == 6);
    assert(Calculation(10, 0.1) == 13);
    assert(Calculation(2, 0.01) == 4);
}
int main()
{
    test_calculation();
    return 0;
}