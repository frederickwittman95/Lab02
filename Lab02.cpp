// Frederick Wittman
// Dr. Robin Hill
// COSC 2030-01
// 24 February 2019

#include "stdafx.h"
#include <iostream>

using namespace std;

class Node  //See your textbook Fig. 4.4
{
public:
	double datum;
	Node * nextnode;
	// Constructor
	Node()
	{
		datum = 0.0;
		nextnode = NULL;
	}
};


int main()
{
	cout << "LLList starting." << endl;

	//Create the first node and its pointer.
	Node * head = new Node;
	head->datum = 7853.84;

	//Now let's create a new node, with a datum.
	Node * tmp = new Node;
	tmp->datum = 3462.01;

	//Now we have two Nodes floating around... but they are not connected.
	//We connect them by putting tmp's address in the nextnode of the head.
	head->nextnode = tmp;

	// Add nodes to the list
	Node * third = new Node;
	Node * fourth = new Node;
	Node * fifth = new Node;

	// Initialize data for new nodes
	third->datum = 100;
	fourth->datum = 200;
	fifth->datum = 300;

	// Connect nodes
	tmp->nextnode = third;
	third->nextnode = fourth;
	fourth->nextnode = fifth;

	//Let's see if we can get to both of them, and write them out.
	Node * currentnode = head;

	// Variables for size of list and sum of doubles
	int sizeOfList = 0;
	double sumOfDoubles = 0;

	while (currentnode != NULL)
	{
		cout << "Datum is " << currentnode->datum << endl;
		sumOfDoubles = sumOfDoubles + currentnode->datum;
		currentnode = currentnode->nextnode;
		sizeOfList++;
	}
	
	cout << "The size of the list is " << sizeOfList << "." << endl;
	cout << "The sum of the data is " << sumOfDoubles << "." << endl;

	// Insert a new node as the third node in the list
	Node * newThird = new Node;
	tmp->nextnode = newThird;
	newThird->nextnode = third;
	newThird->datum = 400;

	// Delete the second node in the list
	head->nextnode = newThird;
	delete tmp;

	// Print again to make sure the insertion and deletion operations were successful
	sizeOfList = 0;
	sumOfDoubles = 0;
	currentnode = head;

	cout << endl << "The new list is:" << endl;

	while (currentnode != NULL)
	{
		cout << "Datum is " << currentnode->datum << endl;
		sumOfDoubles += currentnode->datum;
		currentnode = currentnode->nextnode;
		sizeOfList++;
	}

	cout << "The size of the list is " << sizeOfList << "." << endl;
	cout << "The sum of the data is " << sumOfDoubles << "." << endl;

	return 0;
}


