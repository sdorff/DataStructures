#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;

//prints an array
void Print(int* a, int s) {
	for (int i = 0; i < s; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
//uses bubble sort to sort array
void BubbleSort(int* a, int n) {
	int temp;
	//runs through the list enough times to sort the list
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i -1; j++) {
			//swaps values if value is higher on the left
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
//uses insertion sort to sort array
void InsertionSort(int* a, int n) {
	int j;
	int k;

	for (int i = 0; i < n; i++) {
		k = a[i];
		j = i - 1;
		//cycles through values greater than k
		while (j >= 0 && a[j] >= k) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = k;
	}
}

// combines all of the seperated arrays
void Merge(int* a, int leftstart, int rightend, int mid){
	int left, right, index;
	int* temp = new int[rightend - leftstart + 1];
	left = leftstart;
	index = 0;
	right = mid + 1;

	// Merges both parts into a temorary array
	while (left <= mid && right <= rightend){
		if (a[left] < a[right]){
			temp[index] = a[left];
			index++;
			left++;
		}
		else{
			temp[index] = a[right];
			index++;
			right++;
		}
	}

	// Inserts all the remaining values from the left into temp
	while (left <= mid){
		temp[index] = a[left];
		index++;
		left++;
	}

	// Inserts all the remaining values from the right side
	while (right <= rightend){
		temp[index] = a[right];
		index++;
		right++;
	}


	// puts the values from temp into a
	for (left = leftstart; left <= rightend; left++){
		a[left] = temp[left - leftstart];
	}
}

// separates the arrays
void MergeSort(int* a, int leftstart, int rightend){
	int mid;
	if (leftstart < rightend){
		mid = (leftstart + rightend) / 2;
		// Splits the data
		MergeSort(a, leftstart, mid);
		MergeSort(a, mid + 1, rightend);
		Merge(a, leftstart, rightend, mid);
	}
}
//creates a partition in the array
int Partition(int* a, int leftstart, int rightend) {

	int pivot = a[rightend];    
	int temp;
	int i = (leftstart - 1);  

	for (int j = leftstart; j <= rightend - 1; j++) {

		if (a[j] <= pivot) {
			i++; 
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

	temp = a[i + 1];
	a[i + 1] = a[rightend];
	a[rightend] = temp;
	return (i + 1);
}
//uses quick sort to sort the array
void QuickSort(int* a, int leftstart, int rightend) {
	if (leftstart < rightend) {
		int part;
		part = Partition(a, leftstart, rightend);
		//sorts before and after partition
		QuickSort(a, leftstart, part - 1);
		QuickSort(a, part + 1, rightend);
	}
}
//returns the max value in the array
int GetMax(int* a, int n) {
	int max = a[1];

	for (int i = 2; i <= n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	return max; 
}

/*void CountingSort(int* a, int n) {
	int* out = new int[n + 1];
	int max = GetMax(a, n);
	int* count = new int[max + 1];
	//set count array to 0 for every value
	for (int i = 0; i <= max; i++) {
		count[i] = 0;     
	}
	//increases the count number in array
	for (int i = 1; i <= n; i++) {
		count[a[i]]++;     
	}
	//finds the frequency
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];     
	}
	//orders values in out array
	for (int i = n; i >= 1; i--) {
		out[count[a[i]]] = a[i];
		count[a[i]] -= 1; 
	}
	//transfers out array to original array
	for (int i = 1; i <= n; i++) {
		a[i] = out[i]; 
	}
}*/

void CountingSort(int* a, int n, int range) {
	int* out = new int[n];
	int i;
	int* count = new int[range + 1];

	for (i = 0; i < range; i++) {
		count[i] = 0;
	}
	
	// Stores occurences in count
	for (i = 0; i < n; i++) {
		count[(a[i])]++;
	}

	//changes count to hold actual value
	for (i = 1; i <= range; ++i) {
		count[i] += count[i - 1];
	}

	// puts values in out array
	for (i = 0; a[i]; ++i) {
		out[count[a[i]] - 1] = a[i];
		--count[a[i]];
	}

	//puts out values into original array
	for (i = 0; i < n; i++) {
		a[i] = out[i];
	}
}


void radixsort(int* a, int n)
{
	// finds the max digit number
	int m = GetMax(a, n);

	//calls counting sort
	for (int range = 1; m / range > 0; range *= 10) {
		CountingSort(a, n, range);
	}
}


int main(){
	int n;
	srand(time(0));
	cout << "How many elements do you want in your array? \n";
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (2 * n);
	}

	Print(arr, n);

	CountingSort(arr, n, n * 2);

	Print(arr, n);

	return 0;
}
