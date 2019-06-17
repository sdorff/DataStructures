#include <iostream>
using namespace std;


const int n = 10;


int main () {

int tempLoc;
const int sizeofArray = n;
int sortingArray[sizeofArray];
int length = n;
int end = n;

for (int counter = length - 1; counter > 0; counter--)
{
	for (int i = 0; i < sizeofArray; i++)
	{
	   sortingArray[i] = rand() % 20;

		if (sortingArray[i] > sortingArray[i + 1])
		{
			tempLoc = sortingArray[i + 1];
			sortingArray[i + 1] = sortingArray[1];
			sortingArray[i] = tempLoc;
		}
		end--;
	}

	for (int i = 0; i < sizeofArray; i++)
	{
		cout << sortingArray[i] << endl;
	}
}

}