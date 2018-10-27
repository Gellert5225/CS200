/*
	Li, Gellert
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
	}
	Node *p = root;
	while (p->llink != nullptr || p->rlink != nullptr) {
		if (item < p->data) {
			if (p->llink == nullptr) break;
			else p = p->llink;
		}
		else if (item > p->data) {
			if (p->rlink == nullptr) break;
			else p = p->rlink;
		}
		else std::cerr << "The item to insert is already in the list - duplicates are not allowed" << std::endl;
	}
	if (item < p->data) p->llink = newNode;
	else if (item > p->data) p->rlink = newNode;
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