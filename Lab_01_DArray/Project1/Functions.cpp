/*
	Li, Gellert

	CS A200
	2nd September, 2018

	Lab 01
*/

#include "DArray.h"

// Definition function emptyArray
void DArray::emptyArray() {
	numOfElements = 0;
}

// Definition function appendArray
void DArray::append(const DArray &arr) {
	int newCapacity = arr.numOfElements + numOfElements;
	if (arr.numOfElements != 0) {
		if (newCapacity > capacity) {
			DArray temp = DArray(*this);
			temp.capacity = newCapacity;

			delete[] a;
			a = new int[newCapacity];
			*this = temp;
		}

		for (int i = 0; i < arr.numOfElements; i++) {
			addElement(arr.a[i]);
		}
	}
}

// Definition move constructor
DArray::DArray(DArray &&arr) {
	a = arr.a;

	numOfElements = arr.numOfElements;
	capacity = arr.capacity;

	arr.a = nullptr;

	arr.numOfElements = 0;
	arr.capacity = 0;
}

// Definition move assignment operator
DArray& DArray::operator=(DArray &&arr) {
	if (&arr == this) {
		cerr << "Cannot copy from the same object" << endl;
	} else {
		delete[] a;
		a = arr.a;

		numOfElements = arr.numOfElements;
		capacity = arr.capacity;	

		arr.a = nullptr;

		arr.numOfElements = 0;
		arr.capacity = 0;
	}

	return *this;
}


