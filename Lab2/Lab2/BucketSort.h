/*
	Li, Gellert
	Tang, Paul

	CS A200

	19th September, 2018
	Lab 02
*/

#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include "Bucket.h"
#include <vector>

class BucketSort {
public:
	void insert(const std::vector<double> &v);
	BucketSort();
	~BucketSort();
	void print();
	void createSortedList(Bucket &bucket) const;

public:
	int numberOfElements;
	Bucket** bucket;
};

#endif
