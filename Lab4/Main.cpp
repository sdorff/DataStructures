#include <iostream>
#include "LinkedList.h"
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

//main for task 3
/*int main() {
	int c = 1;//tracks usage of class
	int n;
	int d;//used for the storage of the data value
	int cons;//use stack or queue
	int s = 20;//size of list
	do {
		cout << "Would you like to use a stack or a queue. For Stack enter 1 or 2 for queue. \n";
		cin >> cons;
	
		if (cons == 1) {
			Stack data;
			while (c != 0) {
				cout << "Choose the number of what method you want to use: \n0. Exits the program \n1. Add an item \n2. Get an item \n3. See if an item is in the list \n4. See if the list is empty \n5. See if the list is full \n6. See the size off the list \n7. Display the list \n8. Clear the items in the list \n";
				cin >> n;

				//stops the program
				if (n == 0) {
					break;
				}
				//adds item to list
				else if (n == 1) {
					cout << "You have chosen to add an item" << endl;
					cout << "Enter a non decimal number for your item: " << endl;
					cin >> d;
					data.AddItem(d);
				}
				//removes an item
				else if (n == 2) {
					cout << "Your item is " << data.GetItem() << endl;
				}
				//returns if a student is in the list
				else if (n == 3) {
					cout << "What is the number for the item: " << endl;
					cin >> d;
					cout << data.IsInList(d) << endl;
				}
				//checks if the list is empty
				else if (n == 4) {
					cout << data.IsEmpty() << endl;
				}
				//checks if list is full
				else if (n == 5) {
					cout << data.IsFull() << endl;
				}
				//retuns the size of the list
				else if (n == 6) {
					cout << "The list is " << data.Size() << " items big" << endl;
				}
				//displays the list
				else if (n == 7) {
					data.Display();
				}
				//clears the items in the list
				else if (n == 8) {
					data.ClearList();
					cout << "The list has been cleared. \n";
				}
				//re promts the user
				else {
					cout << "Your input value must be between 0 and 8";
				}
			}
		}
		else if (cons == 2) {
			Queue data;
			while (c != 0) {
				cout << "Choose the number of what method you want to use: \n0. Exits the program \n1. Add an item \n2. Get an item \n3. See if an item is in the list \n4. See if the list is empty \n5. See if the list is full \n6. See the size off the list \n7. Display the list \n8. Clear the items in the list \n";
				cin >> n;

				//stops the program
				if (n == 0) {
					break;
				}
				//adds item to list
				else if (n == 1) {
					cout << "You have chosen to add an item" << endl;
					cout << "Enter a non decimal number for your item: " << endl;
					cin >> d;
					data.AddItem(d);
				}
				//removes an item
				else if (n == 2) {
					cout << "Your item is " << data.GetItem() << endl;
				}
				//returns if a student is in the list
				else if (n == 3) {
					cout << "What is the number for the item: " << endl;
					cin >> d;
					cout << data.IsInList(d) << endl;
				}
				//checks if the list is empty
				else if (n == 4) {
					cout << data.IsEmpty() << endl;
				}
				//checks if list is full
				else if (n == 5) {
					cout << data.IsFull() << endl;
				}
				//retuns the size of the list
				else if (n == 6) {
					cout << "The list is " << data.Size() << " items big" << endl;
				}
				//displays the list
				else if (n == 7) {
					data.Display();
				}
				//clears the items in the list
				else if (n == 8) {
					data.ClearList();
					cout << "The list has been cleared. \n";
				}
				//re promts the user
				else {
					cout << "Your input value must be between 0 and 8";
				}
			}
		}
		else {
			cout << "Please choose 1 or 2" << endl; \

		}
	}while (cons != 2 && cons != 3);

	

	return 0;
}*/

//main for task 2
int main() {
	int c = 1;//tracks usage of class
	int n;
	int d;//used for the storage of the data value
	int cons;//tracks which consturctor to use
	int s = 20;//size of list
	cout << "If you would like to set the size of the list to something other than 20 enter 1 other wise enter 0. \n";
	cin >> cons;
	if (cons == 1) {
		cout << "Enter a number for how long your list to be. \n";
		cin >> s;
	}
	List data(s);
	

	while (c != 0) {
		cout << "Choose the number of what method you want to use: \n0. Exits the program \n1. Add an item \n2. Get an item \n3. See if an item is in the list \n4. See if the list is empty \n5. See if the list is full \n6. See the size off the list \n7. Display the list \n8. Clear the items in the list \n";
		cin >> n;

		//stops the program
		if (n == 0) {
			break;
		}
		//adds item to list
		else if (n == 1) {
			cout << "You have chosen to add an item" << endl;
			cout << "Enter a non decimal number for your item: " << endl;
			cin >> d;
			data.AddItem(d);
		}
		//removes an item
		else if (n == 2) {
			cout << "What is the number for the item: " << endl;
			cin >> d;
			cout << "Your item is " << data.GetItem(d) << endl;
		}
		//returns if a student is in the list
		else if (n == 3) {
			cout << "What is the number for the item: " << endl;
			cin >> d;
			cout << data.IsInList(d) << endl;
		}
		//checks if the list is empty
		else if (n == 4) {
			cout << data.IsEmpty() << endl;
		}
		//checks if list is full
		else if (n == 5) {
			cout << data.IsFull() << endl;
		}
		//retuns the size of the list
		else if (n == 6) {
			cout << "The list is " << data.Size() << " items big" << endl;
		}
		//displays the list
		else if (n == 7) {
			data.Display();
		}
		//clears the items in the list
		else if (n == 8) {
			data.ClearList();
			cout << "The list has been cleared. \n";
		}
		//re promts the user
		else {
			cout << "Your input value must be between 0 and 8";
		}
	}

	return 0;
}