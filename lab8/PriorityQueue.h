#pragma once

class PriorityQueue {
private:
	struct node
	{
		int data;
		int p;
		struct node* next;
	}*front = NULL, * back, * m, * temp, * current;

	struct node* i, * j, * k;
public:

	void add(int element, int priority);
	void sorting();
	void remove();
	void print();
};
