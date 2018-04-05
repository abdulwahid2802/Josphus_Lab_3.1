#pragma once
#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<time.h>

using namespace std;

class List
{
	typedef struct Node
	{
		int data;
		Node *next;
	}*Nptr;			// makes an alie to the name "Node" 
					// which will be a pointer data type. 
					// Nptr n; gives a Node pointer called n

	Nptr head;
	Nptr tail;
	int count;

	// creates a new node and sends to be added
	void createNode(int);

	// adds the new node to the list in 3 ways
	void addNode_linear(Nptr &, Nptr);			// adds in linear time
	void addNode_iterative(Nptr &, Nptr);		// adds iteratively
	void addNode_recursive(Nptr &, Nptr);		// adds with recursion

	// Josephus helper methods
	void findVictim(int);
	void killVictim(Nptr &, Nptr );

	bool isEmpty()const;

public:
	List();
	void insert(int);
	void print()const;
	void josephus(int);
};

