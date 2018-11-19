/*
	Li, Gellert
	Tang, Paul
	CS A200

	26th Oct 2018
	Lab 03
*/

#include "BST.h"


// Definition function insert (non-recursive) 
void BST::insertNonRec(int item) {
	Node *newNode = new Node();
	newNode->data = item;
	if (root == nullptr) {
		root = newNode;
	} else {
		Node *current = root;
		Node *prev = nullptr;

		while (current != nullptr) {
			prev = current;
			if (current->data < item) current = current->rlink;
			else if (current->data > item) current = current->llink;
			else {
				std::cerr << "The item to insert is already in the list - duplicates are not allowed" << std::endl;
				break;
			}
		}
		if (item < prev->data) prev->llink = newNode;
		else if (item > prev->data) prev->rlink = newNode;
	}
}

// Definition function totalNodes
int BST::totalNodes() const {
	return totalNodes(root);
}

// Definition function totalNodes (recursive)
int BST::totalNodes(const Node* node) const {
	int count = 1;
	if (root == nullptr) return 0;
	if (node->llink != nullptr) 
		count += totalNodes(node->llink);
	if (node->rlink != nullptr)
		count += totalNodes(node->rlink);
	return count;
}

// Definition overloaded function preorderTraversal
void BST::preorderTraversal() const {
	if (root == nullptr) cerr << "There is no tree.";
	else preorderTraversal(root);
}

// Definition overloaded function preorderTraversal (recursive)
void BST::preorderTraversal(const Node* node) const {
	if (node != nullptr) {
		cout << node->data << " ";
		preorderTraversal(node->llink);
		preorderTraversal(node->rlink);
	}
}
// Definition overloaded function postorderTraversal
void BST::postorderTraversal() const {
	if (root == nullptr) cerr << "There is no tree.";
	else postorderTraversal(root);
}

// Definition overloaded function postorderTraversal (recursive)
void BST::postorderTraversal(const Node* node) const {
	if (node != nullptr) {
		postorderTraversal(node->llink);
		postorderTraversal(node->rlink);
		cout << node->data << " ";
	}
}