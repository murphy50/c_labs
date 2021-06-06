#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cassert>
#include "tree.cpp"
#include "tree.h"

void test_find_max(Tree<int>& tr) {
    Node<int>* tmp = tr.find_max(tr.root);
    assert(tmp->data == 30);
    tr.insert_node(1000);
    tmp = tr.find_max(tr.root);
    assert(tmp->data == 1000);
}

void test_delete_node(Tree<int>& tr) {
    Node<int>* node = tr.find_node(tr.root, 1000);
    tr.delete_node(node);
    assert(tr.find_node(tr.root, 1000) == nullptr);
    tr.delete_node(tr.root);
    assert(tr.root->data == 20);
}

void test_merge_trees(Tree<int>& first, Tree<int>& sec) {
    Tree<int> third;
    third.root = first.merge_trees(sec.root);
    assert(third.root->data == 7);
    Node<int>* tmp = third.find_max(third.root);
    Node<int>* tmp2 = third.find_min(third.root);
    assert(tmp->data == 30);
    assert(tmp2->data == 4);

}
int main() {
    Tree<int> test;
    test.insert_node(10);
    test.insert_node(5);
    test.insert_node(20);
    test.insert_node(30);
    test.insert_node(4);
    test.insert_node(6);
    test_find_max(test);
    test_delete_node(test);
    Tree<int> test2;
    test.insert_node(7);
    test.insert_node(5);
    test.insert_node(4);
    test.insert_node(6);
    test.insert_node(8);
    test.insert_node(9);
    test_merge_trees(test, test2);
}