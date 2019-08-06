#include <iostream>
#include <cstdlib>
#include "PriorityQueue.h"
#include "Heap.h"
using namespace std;

/*int main()
{
	int ch, priority, element;
	PriorityQueue list;

	do
	{
		cout << "1.Inserting into a Priority Queue " << "2.Deletion " << "3.Display " << " 4.EXIT";
		cout << endl << " Enter u r choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << endl << "enter the element u want insert :";
			cin >> element;
			cout << endl << "enter the priority :";
			cin >> priority;
			list.insert(element, priority);
			break;
		case 2:
			list.del();
			break;
		case 3:
			list.sort();
			list.display();
			break;
		case 4:
			exit(0);
		}
	} while (ch < 5);
}*/

int main() {
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
			data.insert(val, n);
			n = n + 1;
			break;
		case 2:
			cout << "Enter value to delete";
			cin >> x;
			data.del(x, n);
			break;
		case 3:
			data.display(n);
			break;
		case 4:
			exit(0);
		}
	}
	return 0;
}