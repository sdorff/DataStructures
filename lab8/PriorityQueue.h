#pragma once

class PriorityQueue {
private:
	struct node
	{
		int data;
		int pr;
		struct node* next;
	}*front = NULL, * rear, * nn, * temp, * cur;

	struct node* i, * j, * k;
public:

	void insert(int ele, int prior);
	void sort();
	void del();
	void display();
};
