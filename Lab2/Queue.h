#pragma once
#include <iostream>
#include <array>
#include <cmath>

class Queue {

public:
	int data[10];
	int front = 0;
	int back = 0;	
	bool isFull();
	bool isEmpty();
	void enqueue(int n);
	int dequeue();
	int length();


};