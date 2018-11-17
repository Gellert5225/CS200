/*
	Li, Gellert
	CS A200

	26th Oct 2018
	Lab 03
*/

#include "BST.h"

#include <iostream>
#include <fstream>

using namespace std;

void processTree(BST&,char fileName[]);

void testTree(const BST& bst);

int main()
{
	cout << "TESTING: int_1 BST\n\n";
	BST int1BST;
	char fileNameInt1[] = "data_int_1.txt";
	processTree(int1BST,fileNameInt1);
	testTree(int1BST);

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: int_2 BST\n\n";
	BST int2BST;
	char fileNameInt2[] = "data_int_2.txt";
	processTree(int2BST,fileNameInt2);
	testTree(int2BST);

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: int_3 BST\n\n";
	BST int3BST;
	char fileNameInt3[] = "data_int_3.txt";
	processTree(int3BST, fileNameInt3);
	testTree(int3BST);

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: Searching...\n\n";

	cout << "Searching for 9..." << (int1BST.search(9) ? "Found" : "Not Found") << endl;
	cout << "Searching for 0..." << (int1BST.search(0) ? "Found" : "Not Found") << endl;
	cout << "Searching for 17..." << (int1BST.search(17) ? "Found" : "Not Found");

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: Deleting...\n\n";
	cout << "Deleting 13..." << endl;
	int1BST.deleteNode(13);
	testTree(int1BST);

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: Deleting tree...\n\n";
	int1BST.destroyTree();
	testTree(int1BST);

	cout << endl << endl;
	system("Pause");
	return 0;
}

void processTree(BST& bst, char fileName[])
{
	ifstream infile;
	infile.open(fileName);

	if(!infile)
        cerr << "Cannot open the input file." << endl;
	else
	{
		int data;	
		infile >> data;
		
		while (data != -999)
        {
			 bst.insertNonRec(data);
			 infile >> data;	
        }

		infile.clear(); //reset eof for next input
     }

     infile.close();
}

void testTree(const BST& bst)
{
	//TEST: inorderTraversal
	cout << "Inorder traversal: ";
	bst.inorderTraversal();

	//other testcases

	//TEST: totalNodes
	cout << "\nTotal nodes: " << bst.totalNodes();
}
