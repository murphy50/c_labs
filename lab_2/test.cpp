#include<iostream>
#include<assert.h>
using namespace std;

size_t len(int n) {
  if(n==0){
      return 1;
  }
  size_t count = 0;
  while (n != 0) {
    count++;
    n /= 10;
  }
  return count;
}
void test_len(){
    assert(len(10)==2);
    assert(len(1)==1);
    assert(len(12345)==5);
    assert(len(-12)==2);
    assert(len(0)==100);
}
int main(){
    test_len();    
    return 0;
}