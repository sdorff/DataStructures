#include "Stack.h"
using namespace std;

int Stack::GetItem(){
	Node* del = NULL;
	temp = head;
	current = head;
	if (head == NULL) {
		cout << "The list is empty" << endl;
		return NULL;
	}
	else {
		while (current->next != NULL) {
			temp = current;
			current = current->next;
		}
		del = current;
		current = current->next;
		temp->next = current;
		int retVal = del->data;
		delete del;
		return retVal;
	}
}
