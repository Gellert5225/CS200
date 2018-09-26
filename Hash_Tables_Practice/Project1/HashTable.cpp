#include "HashTable.h"

// Implementation of member functions
// of the class HashTable.

HashTable::HashTable() {
	ht = new int[CAP];

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

	memcpy(&ht, &table, table.cap * sizeof(int));

	// OR
	/*
	for (int i = 0; i < table.cap; i++) {
		ht[i] = table.ht[i];
	}
	*/
}

HashTable & HashTable::operator=(const HashTable & table) {
	if (&table != this) {
		if (cap != table.cap) {
			delete[] ht;
			ht = new int[table.cap];
			cap = table.cap;
		}
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

int HashTable::hashValue(const int key, const int c) { 
	// for simplicity, we assume h(k) = key mod n   for linear probing, and
	// f(k) = key   for quadratic

	int hash = key % cap; // replace this with proper function.
	int j = 0;

	if (COLLISION == 0) {
		while (ht[hash] != -1) {
			hash++;
		}
	} else if (COLLISION == 1) {
		while (ht[(key + j * c) % cap] != -1) {
			j++;
			hash = (key + j * c) % cap;
		}
	} else if (COLLISION == 2) {
		while (ht[(key + j * j) % cap] != -1) {
			// TODO: checking repeating and rehash.
			j++;
			hash = (key + j * j) % cap;
		}
	} else if (COLLISION == 3) {

	}

	return hash;
}
