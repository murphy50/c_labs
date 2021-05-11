#include "computing.h"
#include <assert.h>



void test_len(){
    assert(len(10)==2);
    assert(len(1)==1);
    assert(len(12345)==5);
    assert(len(-12)==2);
    assert(len(0)==0);
}
