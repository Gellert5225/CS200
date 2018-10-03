#include "HashTable.h"

#include <iostream>
using namespace std;

int main()
{
	// Add your testing cases here.

	HashTable HT;

	HT.insertKey(506643548);
	HT.insertKey(281942902);
	HT.insertKey(233667136);
	HT.insertKey(155778322);
	HT.insertKey(155778348);
	HT.insertKey(656132722);
	HT.insertKey(984357152);
	HT.insertKey(687056857);
	HT.insertKey(235463598);

	cout << endl << "Hash Table: " << HT << endl << endl;

	cout << "Searching 281942902..." << (HT.searchKey(281942902) ? "Found" : "Not Found") << endl;
	cout << "Searching 155778322..." << (HT.searchKey(155778322) ? "Found" : "Not Found") << endl << endl;
	cout << "Deleting 155778322..." << endl << endl;
	HT.deleteKey(155778322);

	cout << "Deleting 15577832..." << endl << endl;
	HT.deleteKey(15577832);

	cout << endl << "Hash Table: " << HT << endl;

	cout << endl;
	system("Pause");
	return 0;
}