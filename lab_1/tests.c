#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

void TestLen(){
    assert(Len(10)==2);
    assert(Len(1)==1);
    assert(Len(12345)==5);
    assert(Len(-12)==2);
    assert(Len(0)==1);
}

int main(){
    TestLen();
    return 0;
}