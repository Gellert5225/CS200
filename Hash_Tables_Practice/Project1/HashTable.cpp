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

	for (int i = 0; i < table.cap; i++) {
		ht[i] = table.ht[i];
	}
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
	}
	else {
		cerr << "Attempted assignment to itself." << endl;
	}

	return *this;
}
