#include "tree.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
template <class T>
Tree<T>::Tree() {
	root = nullptr;
}

template <class T>
Tree<T>::~Tree() {
	delete_tree(root);
}

template <class T>
void Tree<T>::delete_tree(Node<T>* node) {
	if (node != nullptr) {
		delete_tree(node->left);


		delete_tree(node->right);
		delete(node);
	}
}

template <class T>
void Tree<T>::insert_node(const T& value) {
	Node<T>* node = new Node<T>(value);
	Node<T>* ptr = root;
	Node<T>* prev_ptr = ptr;
	while (ptr != nullptr) {
		prev_ptr = ptr;
		if (value < ptr->data) {
			ptr = ptr->left;
		}
		else {
			ptr = ptr->right;
		}
	}
	node->parent = prev_ptr;
	if (root == nullptr) {
		root = node;
	}
	else {
		if (value >= node->parent->data) {
			node->parent->right = node;
		}
		else {
			node->parent->left = node;
		}
	}
}

template<class T>
Node<T>* Tree<T>::delete_node(Node<T>* node)
{
	if (node == nullptr) {
		return nullptr;
	}
	if (node->left != nullptr && node->right != nullptr) {
		Node<T>* tmp_node = node;
		Node<T>* succsessor = find_succsessor(node->data);
		T tmp = node->data;

		node->data = succsessor->data;
		succsessor->data = tmp;
		node = succsessor;
		succsessor = tmp_node;
	}
	Node<T>* children = nullptr;
	if (node->left != nullptr) {
		children = node->left;
	}
	if (node->right != nullptr) {
		children = node->right;
	}
	if (children != nullptr) {
		children->parent = node->parent;
	}
	if (node->parent == nullptr) {
		root = children;
	}
	else {
		if (node == (node->parent)->left) {
			node->parent->left = children;
		}
		else {
			node->parent->right = children;
		}
	}
	delete(node);
	return children;
}
template<class T>
void Tree<T>::print() {
	inorder_walk(root);
}

template<class T>
inline void Tree<T>::inorder_walk(Node<T>* node)
{
	if (node != nullptr) {
		inorder_walk(node->left);
		std::cout << node->data << std::endl;
		inorder_walk(node->right);
	}
}

template<class T>
Node<T>* Tree<T>::find_max(Node<T>* node) {
	while (node->right != nullptr) {
		node = node->right;
	}
	return node;
}

template<class T>
Node<T>* Tree<T>::find_min(Node<T>* node) {
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

template<class T>
Node<T>* Tree<T>::find_node(Node<T>* node, const T& value) {
	if (node == nullptr || value == node->data) {
		return node;
	}
	if (node->data > value) {
		return find_node(node->left, value);
	}
	if (node->data < value) {
		return find_node(node->right, value);
	}
	return nullptr;
}

template<class T>
Node<T>* Tree<T>::find_succsessor(const T& value) {
	Node<T>* node = find_node(root, value);
	if (node == nullptr) {
		return nullptr;
	}
	if (node->right != nullptr) { /* если у нее есть правые дети, то следующий элемент - минимальный в правом поддереве */
		return find_min(node->right);
	}
	Node<T>* node_parent = node->parent;/* иначе - идем вверх и ищем первую связку родитель-левый элемент*/
	while (node_parent != nullptr && node->data >= node_parent->data) {
		node = node->parent;
		node_parent = node_parent->parent;
	}
	return node->parent;
}

template<class T>
Node<T>* Tree<T>::merge_trees(Node<T>* root2)
{
	Node<T>* root1 = this->root;
	std::vector<T> first;
	std::vector<T> second;
	tree_to_vector(root1, first);
	tree_to_vector(root2, second);
	std::vector<T> result = first;
	for (size_t i = 0; i < second.size(); ++i) {
		result.push_back(second[i]);
	}
	std::sort(begin(result), end(result));
	result.erase(std::unique(begin(result), end(result)), end(result));

	return vector_to_bst(result, 0, result.size() - 1);
}

template<class T>
void Tree<T>::tree_to_vector(Node<T>* node, std::vector<T>& v)
{

	if (node != nullptr) {
		tree_to_vector(node->left, v);
		v.push_back(node->data);
		tree_to_vector(node->right, v);
	}
}

template<class T>
Node<T>* Tree<T>::vector_to_bst(std::vector<T>& v, T start, T end)
{
	if (start > end) {
		return nullptr;
	}
	T mid = (start + end) / 2;
	Node<T>* root = new Node<T>(v[mid]);
	root->left = vector_to_bst(v, start, mid - 1);
	root->right = vector_to_bst(v, mid + 1, end);
	return root;
}





