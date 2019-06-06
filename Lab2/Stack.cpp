#include <iostream>
#include <array>

#include <iostream>
#include <array>
#include "Stack.h"
using namespace std;

void Stack::Push(int pushNumber)
{
	if (top == sizeof(array) / sizeof(array[0]) - 1) { //to get the length of the array to see if it is full or not
		cout << "Full Stack" << endl;
	}
	else {
		top++;
		array[top] = pushNumber;
	}
}

//returns a value and shortens the stack
int Stack::Pop()
{
	if (top == -1) {
		cout << "Empty Stack" << endl;
	}
	else {
		data = array[top];
		top--;
		return data;
	}

}

//returns top value without
int Stack::Top()
{
	if (top == -1) {
		cout << "Empty Stack" << endl;
		return 0;
	}
	else {
		return array[top];
	}
	
}

//returns the number of values in the stack
int Stack::Length()
{
	return top + 1;
}