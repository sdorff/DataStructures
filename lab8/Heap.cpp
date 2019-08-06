#include <iostream>
#include "Heap.h"

using namespace std;


void Heap::display(int n) {
	int i;
	if (n == 0) {
		cout << "Heap is empty";
	}
	else {
		for (i = 0; i < n; i++) {
			cout << a[i] << "->";
		}
		cout << endl;
	}
}
void Heap::insert(int num, int location) {
	int pnode;
	while (location > 0) {
		pnode = (location - 1) / 2;
		if (num <= a[pnode]) {
			a[location] = num;
			return;
		}
		a[location] = a[pnode];
		location = pnode;
	}
	a[0] = num;
}
void Heap::del(int num, int &n)
{
	int left, right, i, temp, par;

	for (i = 0; i < n; i++)
	{
		if (num == a[i])
			break;
	}
	if (num != a[i])
	{
		cout << num << "not found in heap" << endl;
		return;
	}
	a[i] = a[n - 1];
	n = n - 1;
	par = (i - 1) / 2;   /*find parent of node i */
	if (a[i] > a[par])
	{
		insert(a[i], i);
		return;
	}
	left = 2 * i + 1; /*left child of i*/
	right = 2 * i + 2; /* right child of i*/
	while (right < n)
	{
		if (a[i] >= a[left] && a[i] >= a[right])
			return;
		if (a[right] <= a[left])
		{
			temp = a[i];
			a[i] = a[left];
			a[left] = temp;
			i = left;
		}
		else
		{
			temp = a[i];
			a[i] = a[right];
			a[right] = temp;
			i = right;
		}
		left = 2 * i + 1;
		right = 2 * i + 2;
	}
	if (left == n - 1 && a[i] < a[left])
	{
		temp = a[i];
		a[i] = a[left];
		a[left] = temp;
	}
}
/*int main() {
	int val, i, x, num;
	while (1)
	{
		cout << "1.Insert " << " 2.Delete" << " 3.Display" << " 4.Quit" << endl << "Enter your choice : ";
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "Enter value to insert";
			cin >> val;
			insert(val, n);
			n = n + 1;
			break;
		case 2:
			cout << "Enter value to delete";
			cin >> x;
			del(x);
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		}
	}
	return 0;
}*/
