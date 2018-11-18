/*
	Sample functions for PE02
*/

#include "BST.h"

/*--------Change the macro to switch between recursive and non-rec functino calls--------*/
#define RECURSIVE 1

// Private
bool BST::search(Node* node, const int element) const {
	if (node->data == element) return true;
	if (node->data < element && node->rlink == nullptr) return false;
	if (node->data > element && node->llink == nullptr) return false;

	if (node->data < element) return search(node->rlink, element);
	else return search(node->llink, element);
}

void BST::deleteNode(Node*& node, const int element) {
	if (element < node->data) deleteNode(node->llink, element);
	else if (element > node->data) deleteNode(node->rlink, element);
	else {
		Node* temp = node;
		if (node->llink == nullptr) {
			node = node->rlink;
			delete temp;
			temp = nullptr;
		} else if (node->rlink == nullptr) {
			node = node->llink;
			delete temp; 
			temp = nullptr;
		} else {
			int predecessorData;
			getPredecessor(node->llink, predecessorData);
			node->data = predecessorData;
			deleteNode(node->llink, predecessorData);
		}
	}
}

void BST::getPredecessor(Node* node, int& data) const {
	while (node->rlink != nullptr) node = node->rlink;
	data = node->data;
}

void BST::copy(Node*& node, const Node* otherNode) {
	if (otherNode == nullptr) node = nullptr;
	else {
		node = new Node();
		node->data = otherNode->data;
		copy(node->llink, otherNode->llink);
		copy(node->rlink, otherNode->rlink);
	}
}

// Public
bool BST::search(const int element) const {
#if RECURSIVE
	return search(root, element);
#else
	Node* current = root;
	while (current != nullptr) {
		if (current->data == element) return true;
		else if (element < current->data) current = current->llink;
		else current = current->rlink;
	}
	return false;
#endif
}

void BST::deleteNode(const int element) {
#if RECURSIVE
	deleteNode(root, element);
#else
	Node* current = root;
	while (current != nullptr) {
		if (current->data == element) {
			Node* temp = current;
			if (current->rlink == nullptr) {
				current = current->llink;
				delete temp;
				temp = nullptr;
			} else if (current->llink == nullptr) {
				current = current->rlink;
				delete temp;
				temp = nullptr;
			} else {

			}
		}
		else if (element < current->data) current = current->llink;
		else current = current->rlink;
	}
#endif
}

BST& BST::operator=(const BST& tree) {
	if (&tree == this) std::cerr << "Cannot assign the object to itself" << std::endl;
	else {
		if (tree.root == nullptr) destroyTree();
		else copy(root, tree.root);
	}
	return *this;
}