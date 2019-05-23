#include <iostream>
#include <array>

myClass stack{
private:
	int array[5] = {1, 2, 3, 4, 5};
	int top;

public: Stack() {
	top = -1;
}
		void Push(int pushNumber) {
			if (top == sizeof(array)/sizeof(array[0]) -1) //to get the length of the array to see if it is full or not
				cout << "Full Stack" << endl;
			return;
		}

		top++;
		array[top] = pushNumber;

		int Pop() {
			if (top == -1)
				cout << "Empty Stack" << endl;
			return;
		}
}