#pragma once
#include "LinkedList.h"

class Stack:public List{
	private:
		Node* head;
		Node* current;
		Node* temp;
		//Node* track;
		int length;
		int size = 0;
	public:
		int GetItem();
};