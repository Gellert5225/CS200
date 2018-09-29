#include "HashTable.h"

#include <iostream>
using namespace std;

int main()
{
	// Add your testing cases here.

	HashTable HT;

	HT.setNumberOfItems(13);

	HT.insertKey(506643548);
	HT.insertKey(281942902);
	HT.insertKey(233667136);
	HT.insertKey(155778322);

	cout << "Searching 281942902..." << (HT.searchKey(281942902) ? "Found" : "Not Found") << endl;
	cout << "Searching 325168113..." << (HT.searchKey(325168113) ? "Found" : "Not Found") << endl;

	cout << endl;
	system("Pause");
	return 0;
}