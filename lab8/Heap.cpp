#include <iostream>
#include "Heap.h"

using namespace std;


void Heap::print(int n) {

	if (n == 0) {

		cout << "Empty heap";

	}
	else {
		for (int i = 0; i < n; i++) {

			cout << x[i] << "->";

		}
		cout << "X" << endl;
	}
}
void Heap::add(int data, int loc) {
	int temp;
	while (loc > 0) {
		temp = (loc - 1) / 2;
		if (data <= x[temp]) {
			x[loc] = data;
			return;
		}
		x[loc] = x[temp];
		loc = temp;
	}
	x[0] = data;
}
void Heap::remove(int data, int &n)
{
	int left, right, i, temp, par;

	for (i = 0; i < n; i++)
	{
		if (data == x[i])
			break;
	}
	if (data != x[i])
	{
		cout << data << "not found in heap" << endl;
		return;
	}
	x[i] = x[n - 1];
	n = n - 1;
	par = (i - 1) / 2;   /*find parent of node i */
	if (x[i] > x[par])
	{
		add(x[i], i);
		return;
	}
	left = 2 * i + 1; /*left child of i*/
	right = 2 * i + 2; /* right child of i*/
	while (right < n)
	{
		if (x[i] >= x[left] && x[i] >= x[right])
			return;
		if (x[right] <= x[left])
		{
			temp = x[i];
			x[i] = x[left];
			x[left] = temp;
			i = left;
		}
		else
		{
			temp = x[i];
			x[i] = x[right];
			x[right] = temp;
			i = right;
		}
		left = 2 * i + 1;
		right = 2 * i + 2;
	}
	if (left == n - 1 && x[i] < x[left])
	{
		temp = x[i];
		x[i] = x[left];
		x[left] = temp;
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
