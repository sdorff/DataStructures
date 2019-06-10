#pragma once
#include <iostream>
#include "Node.h"

class List {
private:
	Node* head;
	Node* current;
	Node* temp;
	//Node* track;
	int length;
	int size = 0;
public:
	//initial values
	List();
	List(int l);
	//adds student to list, takes in MNumber, firstName, lastName, birthday, and gpa
	void AddItem(int data);
	//gets student and deletes it with MNumber
	int GetItem(int m);
	//returns a bool for wether the item is in the list
	bool IsInList(int m);
	//if the list is empty returns true
	bool IsEmpty();
	//if the list is full returns true
	bool IsFull();
	//returns the size of the list
	int Size();
	//returns a value for an item
	//int SeeNext();
	//Sees where each student is in the list loc is the location wanted by the user
	//int SeeAt(int loc);
	//sets seenext(track) value back to the start
	//void Reset();
	//prints out list
	void Display();
	//clears list
	void ClearList();
};