/*
	Li, Gellert

	CS A200

	19th September, 2018
	Lab 02
*/

#include "BucketSort.h"

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	vector<double> v = 
	{ 0.10, 0.90, 0.15, 0.95, 0.85, 
		0.73, 0.56, 0.32, 0.87, 0.11, 
		0.67, 0.34, 0.43, 0.61, 0.03 };

	BucketSort myBucket;
	myBucket.insert(v);

	cout << fixed << showpoint << setprecision(2);
	myBucket.print();
	cout << endl;

	cout << endl;
	system("Pause");
	return 0;
}
