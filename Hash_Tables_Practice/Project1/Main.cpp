#include "HashTable.h"

#include <iostream>
using namespace std;

int main()
{
    // Add your testing cases here.
    
    HashTable HT;
    
    cout << endl << "Hash Table: " << HT << endl;
    
    
    HT.insertKey(506643548);
    
    cout << endl << "Hash Table: " << HT << endl;
    
    HT.insertKey(281942902);
    
    cout << endl << "Hash Table: " << HT << endl;
    
    HT.insertKey(233667136);
    
    cout << endl << "Hash Table: " << HT << endl;
    
    HT.insertKey(155778322);
    
    cout << endl << "Hash Table: " << HT << endl;
    
    HT.insertKey(155778348);
    
    cout << endl << "Hash Table: " << HT << endl;
    
    HT.insertKey(656132722);
    
    cout << endl << "Hash Table: " << HT << endl;
    
    HT.insertKey(984357152);
    
    cout << endl << "Hash Table: " << HT << endl;
    
    HT.insertKey(687056857);
    
    cout << endl << "Hash Table: " << HT << endl;
    
    HT.insertKey(235463598);
    
    cout << endl << "Hash Table: " << HT << endl;
    
    cout << endl << "Hash Table: " << HT << endl << endl;
    
    cout << "Searching 281942902..." << (HT.searchKey(281942902) ? "Found" : "Not Found") << endl;
    cout << "Searching 155778322..." << (HT.searchKey(155778322) ? "Found" : "Not Found") << endl << endl;
    cout << "Deleting 155778322..." << endl << endl;
    HT.deleteKey(155778322);
    
    cout << "Deleting 15577832..." << endl << endl;
    HT.deleteKey(15577832);
    
    cout << endl << "Hash Table: " << HT << endl;
    
    HT.insertKey(155778322);
    
    cout << endl << "Hash Table: " << HT << endl;
    
    cout << "Reset Table" << endl << endl;
    
    HT.resetTable();
    
    cout << "Hash Table: " << HT << endl;
    
    cout << endl;
    system("Pause");
    return 0;
}
