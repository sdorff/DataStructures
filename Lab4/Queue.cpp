#include "Queue.h"
using namespace std;

int Queue::GetItem()
{
	Node* del = NULL;
	temp = head;
	current = head;
	if (head == NULL) {
		cout << "The list is empty" << endl;
		return NULL;
	}
	else {
		head = head->next;
		del = current;
		current = current->next;
		temp->next = current;
		int retVal = del->data;
		delete del;
		return retVal;
	}
}
