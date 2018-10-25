#include "HashTable.h"

// Implementation of member functions
// of the class HashTable.

HashTable::HashTable() {
    ht = new int[CAP];
    numOfItems = 0;
    cap = CAP;
    
    for (int i = 0; i < CAP; i++) {
        ht[i] = -1;
    }
}

HashTable::~HashTable() {
    delete [] ht;
    ht = nullptr;
}

HashTable::HashTable(const HashTable &table) {
    ht = new int[table.cap];
    numOfItems = table.numOfItems;
    cap = table.cap;
    
     for (int i = 0; i < table.cap; i++) {
     ht[i] = table.ht[i];
     }
}

HashTable::HashTable(const int newCap) {
    ht = new int[newCap];
    numOfItems = 0;
    cap = newCap;
    
    for (int i = 0; i < newCap; i++) {
        ht[i] = -1;
    }
}

HashTable::HashTable(HashTable &&table) {
    cap = table.cap;
    numOfItems = table.numOfItems;
    ht = table.ht;
    
    table.ht = nullptr;
}

int HashTable::getNumberOfItems() const {
    return numOfItems;
}

int HashTable::getCapacity() const {
    return cap;
}

void HashTable::setNumberOfItems(const int num) {
    numOfItems = num;
}

void HashTable::setCapacity(const int cap) {
    this->cap = cap;
}

HashTable & HashTable::operator=(const HashTable & table) {
    if (&table != this) {
        if (cap != table.cap) {
            delete[] ht;
            ht = new int[table.cap];
            cap = table.cap;
        }
        numOfItems = table.numOfItems;
        for (int i = 0; i < table.cap; i++) {
            ht[i] = table.ht[i];
        }
    } else {
        cerr << "Attempted assignment to itself." << endl;
    }
    
    return *this;
}

bool HashTable::isEmpty() const {
    return numOfItems == 0;
}

void HashTable::insertKey(const int key) {
    if (numOfItems == cap / 2 && (COLLISION == 2 || COLLISION == 3)) {
        cout << key << " hits the load factor, start rehashing" << endl;
        rehash();
    }
    
    int j = 0;
    int hash = hashValue(key, j);
    while (ht[hash] != -1 && ht[hash] != -2) {
        j++;
        hash = hashValue(key, j);
    }
    
    numOfItems++;
    ht[hash] = key;
}

bool HashTable::searchKey(const int key) const {
    return searchKey(static_cast<double>(key)) != -1;
}

int HashTable::searchKey(const double key) const {
    int intKey = static_cast<int>(key);
    int j = 0;
    int hash = hashValue(intKey, j);
    while (ht[hash] != -1) {
        if (ht[hash] == intKey) return hash;
        j++;
        hash = hashValue(intKey, j);
    }
    return -1;
}

bool isPrime(const int a) {
    for (int i = 2; i <= a / 2; ++i) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

void HashTable::rehash() {
    cout << "Hash Table before rehashing: " << *this << endl;
    int prime = 2 * CAP + 1;
    while (!isPrime(prime)) {
        prime++;
    }
    
    HashTable newTable = HashTable(prime);
    
    for (int i = 0; i < cap; i++) {
        if (ht[i] != -1) {
            newTable.insertKey(ht[i]);
        }
    }
    
    *this = newTable;
    
    cout << "Hash Table after rehashing: " << *this << endl;
}

void HashTable::deleteKey(const int key) {
    bool found = false;
    int j = 0;
    int hash = hashValue(key, j);
    while (ht[hash] != -1) {
        if (ht[hash] == key) {
            ht[hash] = -2;
            found = true;
            break;
        }
        j++;
        hash = hashValue(key, j);
    }
    
    if (!found) cerr << "Cannot find key " << key << endl;
}

void HashTable::resetTable() {
    numOfItems = 0;
    for (int i = 0; i < cap; i++) {
        ht[i] = -1;
    }
}

HashTable & HashTable::operator=(HashTable && table) {
    if (this == &table) {
        cerr << "Cannot copy from the same object" << endl;
    } else {
        delete[] ht;
        cap = table.cap;
        numOfItems = table.numOfItems;
        
        table.ht = nullptr;
    }
    
    return *this;
}

int HashTable::hashValue(const int key, int j) const {
    // for simplicity, we assume h(k) = key mod n   for linear probing, and
    // f(k) = key   for quadratic
    
    int hash = 0; // replace this with proper function.
    
    if (COLLISION == 0) {
        hash = key % cap + j;
    } else if (COLLISION == 1) {
        hash = (key + j * 3) % cap;
    } else if (COLLISION == 2) {
        hash = (key + j * j) % cap;
    } else if (COLLISION == 3) {
        // Assume h'(k) = 7 - (k mod 7)
        hash = key % 13 + j * (7 - key % 7);
    }
    
    cout << "Hash Value for key " << key << ": " << hash << endl;
    
    if (hash >= cap) {
        hash %= cap;
        cout << "WRAPPING...Hash Value for key " << key << ": " << hash << endl;
    }
    
    return hash;
}

ostream& operator<< (std::ostream& stream, const HashTable& HT) {
    for (int i = 0; i < HT.cap; i++) {
        stream << HT.ht[i] << " ";
    }
    
    return stream;
}
