#include "SortedList.h"
#include "BucketSort.h"

SortedList::SortedList() {
}

SortedList::~SortedList() {
}

void SortedList::sortList(const std::vector<double>& items) {
	BucketSort bucketSort;
	bucketSort.insert(items);
	bucketSort.createSortedList(*this);
}
