#pragma once
#include "LinkedList.h"

class Queue :public List {
private:
	int length;
	int size = 0;
public:
	int GetItem();
};