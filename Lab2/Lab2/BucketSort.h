/*
	Li, Gellert

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

public:
	int numberOfElements;
	Bucket** bucket;
};

#endif
