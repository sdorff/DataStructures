#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;

int main(){
	Queue myQueue;
	Stack myStack;

	int c = 1;//tracks class usage
	int p = 1;//tracks usage of a certain class
	int x;//value for inputs


	//sets program for queue or stack
	while (c != 0) {
		cout << "To use a Stack enter 1, to use a Queue enter 2 or 0 to exit: ";//prompts user for class to use
		cin >> c;
		if (c == 1) {
			//loop to complete use stack class
			while (p != 0) {
				cout << "Choose and option: \n0.Exit program. \n1.Add a value to the stack. \n2.Take out a value. \n3.Get the value at the top. \n4.Get the number of values in the stack." << endl;
				cin >> p;
				//exits loop
				if (p == 0) {
					c = 0;
					break;
				}
				//uses push function
				else if (p == 1) {

					cout << "What value would you like to add? " << endl;
					cin >> x;
					myStack.Push(x);
				}
				//uses pop function
				else if (p == 2) {
					cout << "Your value is: " << myStack.Pop() << endl;
				}
				//uses top function
				else if (p == 3) {
					cout << "The value of the top element is: " << myStack.Top() << endl;
				}
				//uses length function
				else if (p == 4) {
					cout << "There are " << myStack.Length() << " elements in your stack." << endl;
				}
				//restarts loop if incorrect value is used
				else {
					cout << "Please enter a valid number." << endl;
				}
			}
		}
		else if (c == 2) {
			//loop to complete the queue
			while (p != 0) {
				cout << "Choose and option: \n0.Exit program. \n1.Add a value to the queue. \n2.Take the front value of the queue. \n3.See if the queue is full. \n4.See if the queue is empty. \n5.Get the length of the queue." << endl;
				cin >> p;
				//exits loop
				if (p == 0) {
					c = 0;
					break;
				}
				//uses enqueue function
				else if (p == 1) {

					cout << "What value would you like to add? " << endl;
					cin >> x;
					myQueue.enqueue(x);
				}
				//uses dequeue function
				else if (p == 2) {
					cout << "Your value is: " << myQueue.dequeue() << endl;
				}
				//uses isFull function
				else if (p == 3) {
					cout << myQueue.isFull() << endl;
				}
				//uses isEmpty function
				else if (p == 4) {
					cout << myQueue.isEmpty() << endl;
				}
				//uses length function
				else if (p == 5) {
					cout << "The length of the queue is: " << myQueue.length() << endl;
				}
				//restarts loop if incorrect value is used
				else {
					cout << "Please enter a valid number." << endl;
				}
			}
		}
		else {
			cout << "Please enter a valid number." << endl;
		}
		
	}
	return 0;
}

