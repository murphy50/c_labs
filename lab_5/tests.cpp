#include <iostream>
#include <cassert>
#include "Stack.h"
#include "CircleList.h"

void test_stack_push(Stack& st_test) {
    st_test.push('k');
    assert(st_test.top->value == 'k');
    st_test.push('f');
    assert(st_test.top->value == 'f');
    assert(st_test.top->next->value == 'k');
}

void test_stack_pop(Stack& st_test) {
    st_test.pop();
    assert(st_test.top->value == 'k');
}

void test_list_get_size(CircleList& ls_test) {
    assert(ls_test.get_size() == 2);
}

void test_list_erase(CircleList& ls_test) {
    ls_test.erase(1);
    assert(ls_test.get_size() == 1);
}

int main() {
    Stack st;
    st.push('a');
    st.push('b');
    Stack st2;
    st2.push('c');
    test_stack_push(st);
    test_stack_pop(st);
    CircleList ls;
    ls.insert(&st, 0);
    ls.insert(&st2, 1);
    test_list_get_size(ls);
    test_list_erase(ls);
    ls.insert(&st2, 1);
}