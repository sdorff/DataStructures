/*#include <iostream> // Insertion sort
using namespace std;


int main() {

	const int n = 10;
	const int sizeofArray = n;
	int sortingArray[n];
	int i;
	int tempLoc;


	for (int i = 0; i < sizeofArray; i++)
	{

		sortingArray[i] = rand() % 20;


		do
		{

			for (i = 0; i < n; i++)
			{

				tempLoc = sortingArray[i + 1];
				if (sortingArray[i + 1] > sortingArray[i])
				{
					sortingArray[i + 1] = sortingArray[i];
					sortingArray[i] = tempLoc;
				}

			}
		} while (sortingArray[0] > sortingArray[1]);
		for (int i = 0; i < sizeofArray; i++)
			cout << sortingArray[i] << endl;
	}
}*/





#include <iostream> // Bubble sort
using namespace std;


int main () {

const int n = 10;
const int sizeofArray = n;
int sortingArray[n]; 
int tempLoc;
int i;

for (int i = 0; i < sizeofArray; i++)
{

	sortingArray[i] = rand() % 20;
}

	for (int i = n - 1; i > 0; i--)
	{
		if (sortingArray[i] < sortingArray[i + 1])
		{

			tempLoc = sortingArray[i + 1];
			sortingArray[i + 1] = sortingArray[i];
			sortingArray[i] = tempLoc;
		}


	}

for (int i = 0; i < sizeofArray; i++)
{
	cout << sortingArray[i] << endl;
}

}
