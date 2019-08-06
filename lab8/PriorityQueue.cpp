#include <iostream>
#include <cstdlib>
#include "PriorityQueue.h"
using namespace std;


void PriorityQueue::add(int element, int priority) {

	m = (struct node*)malloc(sizeof(struct node));

	m->data = element;
	m->p = priority;
	m->next = NULL;

	if (front == NULL) {
		front = m;
		back = m;
		back->next = NULL;
	}
	else {
		back->next = m;
		back = m;
		back->next = NULL;
	}
	//sort();
}
void PriorityQueue::sorting() {
	current = front;

	if (current == back) {
		current = current;
		back = back;
	}
	else {
		for (i = current; i != back; i = i->next) {

			for (j = i; j != back; j = j->next) {
				temp = (struct node*)malloc(sizeof(struct node));
				k = j->next;

				if (j->p >= k->p) {

					temp->data = j->data;
					temp->p = j->p;
					j->data = k->data;
					j->p = k->p;
					k->data = temp->data;
					k->p = temp->p;
				}
			}
		}
	}
}

void PriorityQueue::remove() {
	sorting();

	if (front == NULL) {

		cout << "\n * No items in the queue * \n ";
	}
	else if (front == back) {

		cout << "(" << front->data << ", " << front->p << ")" << " has been removed \n";
		front = back = NULL;
	}

	else {

		cout << "(" << front->data << ", " << front->p << ")" << " has been removed \n";
		front = front->next;
	}
}
void PriorityQueue::print() {
	sorting();
	current = front;

	if (current == NULL) {
		cout << endl << " * No items in the queue *" << endl;
	}
	else if (front == back) {
		cout << "(" << front->data << ", " << front->p << ")" << endl;
	}
	else {
		cout << endl << "Items in the queue: " << endl;
		while (current != NULL) {
			cout << "(" << current->data << ", " << current->p << ")" << endl;
			current = current->next;
		}
	}
	cout << endl;
}
