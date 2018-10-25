/*
	Li, Gellert

	CS A200

	19th September, 2018
	Lab 02
*/

#include "Bucket.h"

#include <iostream>

void Bucket::insert(const double element) {
	if (first == nullptr) { // this bucket has no element
		first = new Node(element, nullptr);
		last = first;
	} else {
		if (element < first->getItem()) { // new element is smaller than first
			first = new Node(element, first);
		} else { // new element is larger than first
			Node *current = first->getLink();
			Node *previous = first;

			while (current != nullptr && current->getItem() < element) {
				current = current->getLink();
				previous = previous->getLink();
			}

			Node *n = new Node(element, current);
			previous->setLink(n);
		}
	}

	numberOfElement++;
}

Bucket::Bucket() {
	first = nullptr;
	last = nullptr;
	numberOfElement = 0;
}

Bucket::~Bucket() {
	Node *temp = first;

	while (first != nullptr) {
		first = first->getLink();
		delete temp;
		temp = first;
	}

	numberOfElement = 0;
}

void Bucket::print() {
	Node *current = first;
	while (current != nullptr) {
		std::cout << current->getItem() << std::endl;
		current = current->getLink();
	}
}

bool Bucket::isEmpty() const {
	return numberOfElement == 0;
}

Bucket & Bucket::operator=(Bucket && bucket) {
	if (&bucket == this) {
		std::cerr << "Cannot assign to it self" << std::endl;
	} else {
		Node *current = first;
		while (first != nullptr) {
			first = first->getLink();
			delete current;
			current = first;
		}
		last = nullptr;

		first = bucket.first;
		last = bucket.last;
		numberOfElement = bucket.numberOfElement;

		bucket.first = nullptr;
		bucket.last = nullptr;
		bucket.numberOfElement = 0;
	}
	return *this;
}

void Bucket::moveAppend(Bucket && bucket) {
	if (&bucket == this) {
		std::cerr << "Cannot append same object" << std::endl;
	} else {
		if (isEmpty()) {
			first = bucket.first;
			last = bucket.last;
		}
		if (!bucket.isEmpty()) {
			last->setLink(bucket.first);
			last = bucket.last;
			numberOfElement += bucket.numberOfElement;

			bucket.first = nullptr;
			bucket.last = nullptr;
			bucket.numberOfElement = 0;
		}
	}
}
