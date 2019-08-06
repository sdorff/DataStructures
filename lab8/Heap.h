#pragma once
#include <iostream>
using namespace std;

class Heap {
private:
	int a[100];
public:
	void display(int n);
	void insert(int num, int location);
	void del(int num, int &n);
};