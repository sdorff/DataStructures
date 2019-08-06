#include <iostream>
#include <cstdlib>
#include "PriorityQueue.h"
#include "Heap.h"
using namespace std;


	


/*int main() {
	int z;
	cout << "Enter 1 for a priority queue or enter 2 for a heap" << endl;
	cin >> z;

	if (z == 1) {
		int ch, priority, element;
		PriorityQueue list;

		do
		{
			cout << "1.Insert into queue \n2.Remove \n3.Display queue \n4.Exit program \nEnter the integer of the operation you want to perform: \n";
			cin >> ch;
			switch (ch)
			{
			case 1:
				cout << "Element value: ";
				cin >> element;
				cout << "Element Priority: ";
				cin >> priority;
				list.add(element, priority);
				break;
			case 2:
				list.remove();
				break;
			case 3:
				list.sorting();
				list.print();
				break;
			case 4:
				exit(0);
			}
		} while (ch < 5);
	}
	else if (z == 2) {

		int val, i, x, num;
		int n = 0;
		Heap data;

		while (1)
		{
			cout << "1.Insert " << " 2.Delete" << " 3.Display" << " 4.Quit" << endl << "Enter your choice : ";
			cin >> num;
			switch (num)
			{
			case 1:
				cout << "Enter value to insert";
				cin >> val;
				data.add(val, n);
				n = n + 1;
				break;
			case 2:
				cout << "Enter value to delete";
				cin >> x;
				data.remove(x, n);
				break;
			case 3:
				data.print(n);
				break;
			case 4:
				exit(0);
			}
		}
	}
	else {
		cout << "Please enter a valid input \n";
	}
	return 0;
}*/

int main() {

	return 0;
}