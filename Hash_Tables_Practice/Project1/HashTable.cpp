#include "HashTable.h"

// Implementation of member functions
// of the class HashTable.

HashTable::HashTable() {
	ht = new int[CAP];
	numOfItems = 0;
	cap = CAP;

	for (int i = 0; i < CAP; i++) {
		ht[i] = -1;
	}
}

HashTable::~HashTable() {
	delete [] ht;
}

HashTable::HashTable(const HashTable &table) {
	ht = new int[table.cap];
	numOfItems = table.numOfItems;
	cap = table.cap;

	memcpy(&ht, &table, table.cap * sizeof(int));

	// OR
	/*
	for (int i = 0; i < table.cap; i++) {
		ht[i] = table.ht[i];
	}
	*/
}

int HashTable::getNumberOfItems() {
	return numOfItems;
}

int HashTable::getCapacity() {
	return cap;
}

void HashTable::setNumberOfItems(const int num) {
	numOfItems = num;
}

void HashTable::setCapacity(const int cap) {
	this->cap = cap;
}

HashTable & HashTable::operator=(const HashTable & table) {
	if (&table != this) {
		if (cap != table.cap) {
			delete[] ht;
			ht = new int[table.cap];
			cap = table.cap;
		}
		numOfItems = table.numOfItems;
		for (int i = 0; i < table.numOfItems; i++) {
			ht[i] = table.ht[i];
		}
	} else {
		cerr << "Attempted assignment to itself." << endl;
	}

	return *this;
}

bool HashTable::isEmpty() const {
	return numOfItems == 0;
}

void HashTable::insertKey(const int key) {
	int j = 0;
	int hash = hashValue(key, j);
	while (ht[hash] != -1) {
		j++;
		hash = hashValue(key, j);
	}

	ht[hash] = key;
}

bool HashTable::searchKey(const int key) {
	int j = 0;
	int hash = hashValue(key, j);
	while (ht[hash] != -1) {
		if (ht[hash] == key) return true;
		j++;
	}
	return false;
}

int HashTable::hashValue(const int key, int j) { 
	// for simplicity, we assume h(k) = key mod n   for linear probing, and
	// f(k) = key   for quadratic

	int hash = 0; // replace this with proper function.

	if (COLLISION == 0) {
		hash = key % cap + j;
	} else if (COLLISION == 1) {
		hash = (key + j * 3) % cap;
	} else if (COLLISION == 2) {
		hash = (key + j * j) % cap;
	} else if (COLLISION == 3) {
		// Assume h'(k) = 7 - (k mod 7)
		hash = key % 13 + j * (7 - key % 7);
	}

	cout << "Hash Value for key " << key << ": " << hash << endl;

	return hash;
}
