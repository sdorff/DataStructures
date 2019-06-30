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
}





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

}*/


//combines all of the halves of the array to a new sorted array
/*void Merge(int* a, int leftstart, int rightend, int mid) {
	int* temp = new int[rightend - leftstart + 1];
	int left = leftstart;
	int right = mid + 1;
	int index = leftstart;


	while (left <= mid && right <= rightend) {
		if (a[left] <= a[right]) {
			temp[index] = a[left];
			left++;
		}
		else {
			temp[index] = a[right];
			right++;
		}
		index++;
	}
	//insert all remaing in left half
	while (left <= mid) {
		temp[index] = a[left];
		left++;
		index++;
	}
	//insert all remaing in right half
	while (right <= rightend) {
		temp[index] = a[left];
		right++;
		index++;
	}

	//insert temp values into a
	for (left = leftstart; left <= rightend; left++) {
		a[left] = temp[left - leftstart];
	}
}

//overloaded recursive merge call
void MergeSort(int* a, int leftstart, int rightend) {
	int mid;
	if (leftstart >= rightend) {
		return;
	}
	mid = (leftstart + rightend) / 2;
	MergeSort(a, leftstart, mid);
	MergeSort(a, mid + 1, rightend);
	Merge(a, leftstart, rightend, mid);

}




int main() {
	int n;
	cout << "How many elements do you want in your array? \n";
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (2 * n);
	}

	MergeSort(arr, 0, n - 1);

	Print(arr, n);

	return 0;
}*/

