/*
	Li, Gellert
	CS A200

	26th Oct 2018
	Lab 03
*/

#ifndef BST_H
#define BST_H

#include <string>		
#include <iostream>
using namespace std;

class Node
{
	friend class BST;
public:
	Node(): data(0), rlink(nullptr), llink(nullptr) {}
	~Node(){}
private:
    int data;
    Node *rlink, *llink;
};

class BST
{
public:

	BST();
	
	void insert(int item); 
	
	void inorderTraversal() const;

	void destroyTree();
	
	~BST();

	// Declaration function insert (non-recursive) 
	// Inserts element in the BST
	void insertNonRec(int item);
	
	// Declaration function totalNodes
	// Returns the number of nodes in the BST
	int totalNodes() const;

	// Declaration overloaded function preorderTraversal
	// Print all nodes in the BST in a preorder sequence
	void preorderTraversal() const;

	// Declaration overloaded function postorderTraversal
	// Print all nodes in the BST in a postorder sequence
	void postorderTraversal() const;

	/*----------Sample Functions for PE02----------*/
	bool search(const int element) const;

	void deleteNode(const int element);

private:	
	Node *root; //Pointer to the root

	void insert(Node* &p, Node *newNode);

	void destroyTree(Node* &p);
	
	void inorderTraversal(const Node* p) const;

	// Declaration overloaded function totalNodes (recursive)
	int totalNodes(const Node* node) const;

	// Declaration overloaded function preorderTraversal (recursive)
	void preorderTraversal(const Node* node) const;

	// Declaration overloaded function postorderTraversal (recursive)
	void postorderTraversal(const Node* node) const;

	/*----------Sample Functions for PE02----------*/
	bool search(Node* node, const int element) const;
	
	void deleteNode(Node*& node, const int element);

	void getPredecessor(Node* node, int& data) const;
};

#endif