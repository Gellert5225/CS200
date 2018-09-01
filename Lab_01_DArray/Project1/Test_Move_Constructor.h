#ifndef MOVE_CONSTRUCTOR_H
#define MOVE_CONSTRUCTOR_H

#include "DArray.h"

#include <iostream>
using namespace std;

void testMoveConstructor()
{
	cout << "\n------------------------------------------\n";
	cout << "TEST move constructor...\n";

	{
		DArray arr1(10);
		int numOfElem1 = 4;
		populateArray(arr1, numOfElem1, START_10);
		cout << "\narr1 = " << arr1;

		cout << "\nMove data from arr1 into arr2...";

		// NEED TO USE THE move FUNCTION FROM <utility>
		DArray arr2 = move(arr1);

		cout << "\narr2 = ";
		cout << arr2;

		cout << "\narr1 should be empty...";
		if (arr1.getNumOfElements() == 0)
			cout << "\narr1 is empty (all elements have been moved.)\n";
		else
			cout << "\nERROR: arr1 is not empty.\n";
	}

	{
		DArray arr1(10);
		int numOfElem1 = 0;
		populateArray(arr1, numOfElem1, START_10);
		cout << "\narr1 = " << arr1;

		cout << "\nMove data from arr1 into arr2...";

		DArray arr2 = move(arr1);
		cout << "\narr2 = ";
		cout << arr2;

		cout << "\narr1 should be empty...";
		if (arr1.getNumOfElements() == 0)
			cout << "\narr1 is empty (all elements have been moved.)\n";
		else
			cout << "\nERROR: arr1 is not empty.\n";
	}

	{
		DArray arr1(10);
		int numOfElem1 = 8;
		populateArray(arr1, numOfElem1, START_10);
		cout << "\narr1 = " << arr1;

		cout << "\nMove data from arr1 into arr2...";

		DArray arr2 = move(arr1);
		cout << "\narr2 = ";
		cout << arr2;

		cout << "\narr1 should be empty...";
		if (arr1.getNumOfElements() == 0)
			cout << "\narr1 is empty (all elements have been moved.)\n";
		else
			cout << "\nERROR: arr1 is not empty.\n";
	}
}

#endif
