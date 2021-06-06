#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "isPeriodic.h"

void test_isPeriodic(){
    assert(IsPeriodic("123123")==1);
    assert(IsPeriodic("12")==0);
    assert(IsPeriodic("1111111")==1);
    assert(IsPeriodic("0")==1);
    assert(IsPeriodic("1")==1);
    assert(IsPeriodic("171717")==1);
}
int main(){
    test_isPeriodic();
}