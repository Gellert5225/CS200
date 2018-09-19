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

private:
	Node* first;
	Node* last;
	int numberOfElement;
};

#endif
