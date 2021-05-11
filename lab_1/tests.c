#include "computing.h"
#include <assert.h>
#include <stdio.h>


#include <stdlib.h>




void test_len(){
    assert(len(10)==2);
    assert(len(1)==1);
    assert(len(12345)==5);
    assert(len(-12)==2);
    assert(len(0)==1);
}
int main(){
    test_len();
    return 0;
}