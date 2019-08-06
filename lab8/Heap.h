#pragma once
#include <iostream>
using namespace std;

class Heap {
private:
	int x[100];
public:
	void print(int n);
	void add(int num, int location);
	void remove(int num, int &n);
};