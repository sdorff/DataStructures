#include <iostream>
#include <cstdlib>
#include "PriorityQueue.h"
#include "Heap.h"
using namespace std;
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;


	


int main() {
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
			cout << "1.Insert into heap \n2.Remove \n3.Display heap order \n4.Exit program \nEnter the integer of the operation you want to perform: \n";
			cin >> num;
			switch (num)
			{
			case 1:
				cout << "Element value: ";
				cin >> val;
				data.add(val, n);
				n = n + 1;
				break;
			case 2:
				cout << "Element value: ";
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
}

/*int main() {
	Heap data;
	PriorityQueue list;
	int temp;
	auto t1 = Clock::now();
	for (int i = 0; i < 800; i++) {
		temp = rand() % 100 + 1;
		data.add(temp, temp);
	}
	auto t2 = Clock::now();
	cout << "Delta t2-t1: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 -t1).count() << " nanoseconds" << std::endl;
	return 0;
}*/