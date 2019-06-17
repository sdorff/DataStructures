#include <iostream>
using namespace std;


int arrayNValues[6] = { 10, 100, 500, 5000, 25000, 100000 };

int main{

int tempLoc;
const int sizeofArray = arrayNValues[0];
int sortingArray[sizeofArray];

for (int i = 0, i < sizeofArray, i++) 
{
	sortingArray[i] = rand() % 2 * sizeofArray;
	cout << sortingArray[i] << endl;
}

}