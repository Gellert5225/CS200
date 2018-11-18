/*
	 Li, Gellert
	 CS A200

	 7th Nov 2018
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Declaration of function processStacks
void processStacks(int* a, size_t& size, const int cap, int& topSmall, int& topLarge);

// Declaration of function printSmallValues
void printSmallValues(const int* a, int& topSmall);

// Declaration of function printLargeValues
void printLargeValues(const int* a, const int cap, int& topLarge);

int main() {
	int cap = 0;

	cout << "Enter max number of integers: ";
	cin >> cap;

	int *a = new int[cap];

	// declare any needed variables
	size_t size = 0;
	int topSmall = -1;
	int topLarge = cap;

	// call to function processStacks
	processStacks(a, size, cap, topSmall, topLarge);

	// call to function printSmallValues
	printSmallValues(a, topSmall);

	cout << endl;
	// call to function printLargeValues
	printLargeValues(a, cap, topLarge);
	// what else?

	cout << endl;
	system("Pause");
	return 0;
}

// Definition of function processStacks
void processStacks(int* a, size_t& size, const int cap, int& topSmall, int& topLarge) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	do {
		size = 0;
		string line;
		cout << "Enter integers (-1 to quit): ";
		getline(cin, line);

		istringstream in(line);

		int num;
		while (in >> num) {
			if (num != -1) {
				if (num > 1000) {
					topLarge--;
					a[topLarge] = num;
				} else {
					topSmall++;
					a[topSmall] = num;
				}
				++size;
			}
		}
		if (size > cap) cout << "Max capacity is " << cap << ", please enter again" << endl;
	} while (size > cap);
}

// Definition of function printSmallValues
void printSmallValues(const int* a, int& topSmall) {
	cout << "Stack with small values (top): ";
	if (topSmall == -1) cout << "There are no small numbers";
	else {
		while (topSmall != -1) {
			cout << a[topSmall] << " ";
			topSmall--;
		}
	}
}

// Definition of function printLargeValues
void printLargeValues(const int* a, const int cap, int& topLarge) {
	cout << "Stack with large values (top): ";
	if (topLarge == cap) cout << "There are no large numbers";
	else {
		while (topLarge != cap) {
			cout << a[topLarge] << " ";
			topLarge++;
		}
	}
}
