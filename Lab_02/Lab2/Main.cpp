/*
	Li, Gellert
	Tang, Paul

	CS A200

	19th September, 2018
	Lab 02
*/

#include "SortedList.h"

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	vector<double> v = 
	{ 0.10, 0.90, 0.15, 0.95, 0.85, 
		0.73, 0.56, 0.32, 0.87, 0.11, 
		0.67, 0.34, 0.43, 0.61, 0.03 };

	SortedList sortedList;
	sortedList.sortList(v);

	cout << fixed << showpoint << setprecision(2);
	sortedList.print();
	cout << endl;

	cout << endl;
	system("Pause");
	return 0;
}
