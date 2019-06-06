#pragma once
#include <iostream>
using namespace std;


class Stack {
private:
	int array[5] = { 1, 2, 3, 4, 5 };
	int top = -1;
	int data;
public:
	void Push(int pushNumber);
	int Pop();
	int Top();
	int Length();
};