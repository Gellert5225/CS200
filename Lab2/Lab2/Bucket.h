/*
	Li, Gellert

	CS A200

	19th September, 2018
	Lab 02
*/

#ifndef BUCKET_H
#define BUCKET_H

class Node { 
public:
	Node() : item(0.0), link(nullptr) {}
	Node(double newItem, Node *newLink) : item(newItem), link(newLink) {}
	Node* getLink() const { return link; }
	double getItem() const { return item; }
	void setItem(double newItem) { item = newItem; }
	void setLink(Node *newLink) { link = newLink; }
	~Node() {}

private:
	double item;
	Node *link; 
};

class Bucket {
public:
	void insert(const double element);
	Bucket();
	~Bucket();
	void print();
	bool isEmpty() const;
	Bucket& operator=(Bucket &&bucket);
	void moveAppend(Bucket &&bucket);

private:
	Node* first;
	Node* last;
	int numberOfElement;
};

#endif
