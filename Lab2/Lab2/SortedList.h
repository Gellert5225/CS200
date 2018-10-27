/*
	Li, Gellert
	Tang, Paul

	CS A200

	19th September, 2018
	Lab 02
*/

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include "Bucket.h"
#include <vector>

class SortedList : public Bucket {
public:
	SortedList();
	~SortedList();

	void sortList(const std::vector<double> &items);
};

#endif