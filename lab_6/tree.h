#ifndef TREE_H
#define TREE_H
#include<vector>
#include<string>
template<class T>
class Node {
public:
	Node(const T& value) {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		data = value;
	}
	
	Node* left;
	Node* right;
	Node* parent;
	T data;
};

template <class T>
class Tree {
public:
	Node<T>* root;
	Tree();
	~Tree();
	void delete_tree(Node<T>* node);
	void insert_node(const T& value);
	Node<T>* delete_node(Node<T>* node);
	void print();
	void inorder_walk(Node<T>* node);// печатает все ключи в неубывающем порядке 
	Node<T>* find_max(Node<T>* node);
	Node<T>* find_min(Node<T>* node);
	Node<T>* find_node(Node<T>* node, const T& value);// ищет ноду по значению, начиная с какой-то позиции 
	Node<T>* find_succsessor(const T& value); // находит элемент с ключем(data), следующим за данным числом, "ищет наследника на свою позицию по значению"
	Node<T>* merge_trees(Node<T>* root2);
	void tree_to_vector(Node<T>* node, std::vector<T>& v);
	Node<T>* vector_to_bst(std::vector<T>& v, T start, T end);
};

#endif
