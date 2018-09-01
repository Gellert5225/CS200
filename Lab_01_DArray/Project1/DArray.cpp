#include "DArray.h"

ostream& operator<<(ostream& out, const DArray& outArray)
{
	for (int i = 0; i < outArray.numOfElements; ++i)
		out << outArray.a[i] << " ";

	return out;
}

DArray::DArray( )
{
    capacity = CAP;
	a = new int[capacity];	
	numOfElements = 0;
}

DArray::DArray(int newCapacity) 
{
	capacity = newCapacity;
    a = new int[capacity];
	numOfElements = 0;	 
}

DArray::DArray(const DArray& otherArray)
{
	//set all member variables of the calling object
	capacity = otherArray.capacity;
	numOfElements = otherArray.numOfElements;

	//create a new array
	a = new int[capacity];

	//copy all elements of the array parameter
	//  onto the calling object
	for (int i = 0; i < numOfElements; ++i)
		a[i] = otherArray.a[i];
}

void DArray::addElement(int newElement)
{
    if (numOfElements >= capacity)
    {
        cerr << "Attempt to exceed capacity in DArray.\n";
        exit(0); 
    }
	else
	{
		a[numOfElements] = newElement;
		++numOfElements;
	}
}

int DArray::getNumOfElements() const
{
	return numOfElements;
}

DArray::~DArray( )
{
    delete [] a; //delete the array
	a = nullptr;	 //null the pointer (not necessary, but good practice)
}

DArray& DArray::operator=(const DArray& otherArray)
{
	//to avoid self assignment, check that the 
	//   parameter passed is not the calling object
	if (&otherArray != this)
	{
		//if the array we are passing has a different
		//  capacity from the calling object,
		//  then we need to create a new array
		if (capacity != otherArray.capacity)
		{
			//deallocate the memory used by 
			//  the calling object and
			//  re-create the object so that 
			//  it has the same capacity
			delete[] a;
			a = new int[otherArray.capacity];

			//update capacity
			capacity = otherArray.capacity;
		}

		//update number of elements	
		numOfElements = otherArray.numOfElements;

		// start copying
		for (int i = 0; i < numOfElements; ++i)
			a[i] = otherArray.a[i];
	}
	else
	{
		cerr << "Attempted assignment to itself.";
	}

	return *this;
}

