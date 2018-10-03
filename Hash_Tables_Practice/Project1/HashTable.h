#ifndef HASHTABLE_H
#define HASHTABLE_H	

#include <iostream>
using namespace std;

const int CAP = 13;	// For testing, you can change it to another prime number.
 
/* define some collision methods: 
	 0 for linear probing without c/j
	 1 for linear probing with c/j
	 2 for quadratic probing
	 3 for double hashing

	Change the number to test different open addressing.
*/
constexpr unsigned int COLLISION = 2;

class HashTable
{
public:

	/*
		Public member functions you should implement:
			Default constructor
				- Set all the indices of the table to -1.
			overloaded constructor
			the Big 5
			accessor functions
			mutator functions
			isEmpty
				- Returns a Boolean
			insertKey 
				- Calls the hashValue function to get the index.
			searchKey
				- Calls the hashValue function to get the index.
				- Returns a Boolean value
			any overloaded operator that could be useful
			deleteKey 
				- Calls the hashValue function to get the index.
				- Mark deleted indices with -2.
			rehash
				- Re-create the table with double the capacity to the next prime number.
			destructor
			resetTable
				- Will re-set to an empty table
	*/
	HashTable();

	~HashTable();

	HashTable(const HashTable &table);

	HashTable(const int newCap);

	int getNumberOfItems();

	int getCapacity();

	void setNumberOfItems(const int num);

	void setCapacity(const int cap);

	HashTable& operator=(const HashTable &table);

	bool isEmpty() const;

	void insertKey(const int key);

	bool searchKey(const int key) const;

	void rehash();

	void deleteKey(const int key);

	friend ostream& operator<< (std::ostream& stream, const HashTable& HT);

private:
	/* 
		Private member functions you should implement:
			hashValue
				Parameters: the key and the j value
				Return value: an int storing an index
			searchKey
				Overloaded function that returns an index
	*/

	int hashValue(const int key, int j) const;

	int searchKey(const float key);

	int *ht;			//pointer to the hash table
	int numOfItems;		//number of items in the hash table
	int cap;			//maximum length of the hash table	
};

#endif