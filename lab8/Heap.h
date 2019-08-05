#pragma once
#include <iostream>
using namespace std;

class Heap {
private:
	int a[100];
public:
	int n = 0;
	void display();
	void insert(int num, int location);
	void del(int num);
};