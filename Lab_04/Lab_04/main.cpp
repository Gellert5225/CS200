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
void printSmallValues(const int* a, const int topSmall);

// Declaration of function printLargeValues
void printLargeValues(const int* a, const int cap, const int topLarge);

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
void printSmallValues(const int* a, const int topSmall) {
	cout << "Stack with small values (top): ";
	if (topSmall == -1) cout << "There are no small numbers";
	else for (int i = topSmall; i >= 0; i--) cout << a[i] << " ";
}

// Definition of function printLargeValues
void printLargeValues(const int* a, const int cap, const int topLarge) {
	cout << "Stack with large values (top): ";
	if (topLarge == cap) cout << "There are no large numbers";
	else for (int i = topLarge; i < cap; i++) cout << a[i] << " ";
}
