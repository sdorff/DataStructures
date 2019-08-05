#include <iostream>
#include <cstdlib>
#include "PriorityQueue.h"
using namespace std;


void PriorityQueue::insert(int ele, int prior)
{
	nn = (struct node*)malloc(sizeof(struct node));
	nn->data = ele;
	nn->pr = prior;
	nn->next = NULL;
	if (front == NULL)
	{
		front = nn;
		rear = nn;
		rear->next = NULL;
	}
	else
	{
		rear->next = nn;
		rear = nn;
		rear->next = NULL;
	}
	//sort();
}
void PriorityQueue::sort()
{
	cur = front;
	if (cur == rear)
	{
		cur = cur;
		rear = rear;
	}
	else
	{
		for (i = cur; i != rear; i = i->next)
		{
			for (j = i; j != rear; j = j->next)
			{
				temp = (struct node*)malloc(sizeof(struct node));
				k = j->next;
				if (j->pr >= k->pr)
				{
					temp->data = j->data;
					temp->pr = j->pr;
					j->data = k->data;
					j->pr = k->pr;
					k->data = temp->data;
					k->pr = temp->pr;
				}
			}
		}
	}
}
void PriorityQueue::del()
{
	sort();
	if (front == NULL)
	{
		cout << "\n * Priority Queue is Empty * \n ";
	}
	else if (front == rear)
	{
		cout << " [" << front->data << "," << front->pr << "]" << " is deleted" << endl;
		front = rear = NULL;
	}
	else
	{
		cout << " [" << front->data << "," << front->pr << "]" << " is deleted" << endl;
		front = front->next;
	}
}
void PriorityQueue::display()
{
	sort();
	cur = front;
	if (cur == NULL)
	{
		cout << endl << " * Priority Queue is Empty *" << endl;
	}
	else if (front == rear)
	{
		cout << " [" << front->data << "," << front->pr << "]" << endl;
	}
	else
	{
		cout << endl << " Elements in Priority Queue are :" << endl;
		while (cur != NULL)
		{
			cout << " [" << cur->data << "," << cur->pr << "]" << endl;
			cur = cur->next;
		}
	}
	cout << endl;
}
