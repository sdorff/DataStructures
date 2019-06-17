#include <iostream>
using namespace std;


int main () {

const int n = 10;
int tempLoc;
const int sizeofArray = n;
int sortingArray[sizeofArray]; 
int length = 10;
int end = 10;

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
}
for (int i = 0; i < sizeofArray; i++)
{
	cout << sortingArray[i] << endl;
}

}