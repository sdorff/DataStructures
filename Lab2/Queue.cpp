#include <iostream>
#include <array>
#include <cmath>
#include "Queue.h"
using namespace std;


//checks if queue is full
bool Queue::isFull(){
	return front == (back + 1) % 10;
}

//checks if queue is empty
bool Queue::isEmpty(){
	if (front == back){
		return true;
	}
	else {
		return false;
	}
}

//adds a value to the queue
void Queue::enqueue(int n){
	if (isFull()) {
		cout << "Queue is full" << endl;
	}
	else {
		back = (back + 1) % 10;
		data[back] = n;
	}
}

//removes a values from the queue
int Queue::dequeue(){
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
	}
	else {
		int v = data[front + 1];
		front = (front + 1) % 10;
		return v;
	}
	return 0;
}

//returns length of queue
int Queue::length(){
	return back - front;
}


