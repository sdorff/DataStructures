#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
using namespace std;

class List {
private:
	struct Student {
		int MNumber;
		string firstName;
		string lastName;
		Student* next;
	};
	Student* head;
	Student* current;
	Student* temp;
	Student* track;
public:
	//initial values
	List() {
		head = NULL;
		current = NULL;
		temp = NULL;
		track = NULL;//value that SeeNext uses
	}
	//adds student to list, takes in MNumber, firstName, lastName, birthday, and gpa
	void AddItem(int m) {
		Student* n = new Student;
		n->next = NULL;
		n->MNumber = m;
		if (head == NULL) {
			head = n;
		}
		else {
			current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			n->next = current->next;
			current->next = n;
		}
	}
	//gets student and deletes it with MNumber
	int GetItem(int m) {
		Student* del = NULL;
		temp = head;
		current = head;
		if (head == NULL) {
			cout << "The list is empty" << endl;
			return NULL;
		}
		else {
			while (current != NULL && current->MNumber != m) {
				temp = current;
				current = current->next;
			}
			if (current == NULL) {
				return NULL;
				delete del;
			}
			else {
				del = current;
				current = current->next;
				temp->next = current;
				if (del = head) {
					head = head->next;
					temp = NULL;
				}
				int retVal = del->MNumber;
				delete del;
				return retVal;
			}
		}

	}
	//returns a bool for wether the item is in the list
	bool IsInList(int m) {
		temp = head;
		current = head;
		while (current != NULL && current->MNumber != m) {
			temp = current;
			current = current->next;
		}
		if (current == NULL) {
			return false;
		}
		else {
			return true;
		}
	}
	//if the list is empty returns true
	bool IsEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	//returns the size of the list
	int Size() {
		temp = head;
		current = head;
		int count = 0;
		while (current != NULL) {
			temp = current;
			current = current->next;
			count++;
		}
		return count;


		return 0;
	}
	//returns a value for an item
	int SeeNext() {
		int n = track->MNumber;
		if (IsEmpty()) {
			cout << "List is empty, please add an item." << endl;
			return NULL;
		}
		else if (track->next == NULL) {
			track = head;
			cout << "This is the last item in the list." << endl;
			return n;
		}
		else {
			track = track->next;
			return n;
		}
	}
	//Sees where each student is in the list loc is the location wanted by the user
	int SeeAt(int loc) {
		current = head;
		for (int i = 1; i < loc; i++) {
			current = current->next;
		}
		track = current;
		return current->MNumber;
	}
	//sets seenext(track) value back to the start
	void Reset() {
		track = head;
	}

	void CountingSort(int n) {
		int t;
		//runs through the list enough times to sort the list
		for (int i = 0; i < n - 1; i++) {
			current = head->next;
			temp = head;

			for (int j = 0; j < n - i - 1; j++) {
				//swaps values if value is higher on the left
				if (temp->MNumber > current->MNumber) {
					t = temp->MNumber;
					temp->MNumber = current->MNumber;
					current->MNumber = t;
				}
				temp = current;
				current = current->next;
			}
		}
	}

	void Display() {
		current = head;
		while (current) {
			cout << current->MNumber << "->";
			current = current->next;
		}
		cout << "X" << endl;
	}

	void BubbleSort(int n) {
		
		int t;
		//runs through the list enough times to sort the list
		for (int i = 0; i < n - 1; i++) {
			 current = head->next;
			 temp = head;

			for (int j = 0; j < n - i - 1; j++) {
				//swaps values if value is higher on the left
				if (temp->MNumber > current->MNumber) {
					t = temp->MNumber;
					temp->MNumber = current->MNumber;
					current->MNumber = t;
				}
				temp = current;
				current = current->next;
			}
		}
	}

	void InsertionSort(int n) {
		int t;
		//runs through the list enough times to sort the list
		for (int i = 0; i < n - 1; i++) {
			current = head->next;
			temp = head;

			for (int j = 0; j < n - i - 1; j++) {
				//swaps values if value is higher on the left
				if (temp->MNumber > current->MNumber) {
					t = temp->MNumber;
					temp->MNumber = current->MNumber;
					current->MNumber = t;
				}
				temp = current;
				current = current->next;
			}
		}
	}

	
};

int main(){
	int n;
	int s;
	srand(time(0));
	cout << "How many elements do you want in your array? \n";
	cin >> n;

	List students;
	for (int i = 0; i < n; i++) {
		students.AddItem(rand() % (2 * n));
	}

	cout << "Choose the number of the sorting method you would like to use. \n1. Bubble Sort \n2. Insertion Sort \n3. Counting Sort \n";
	cin >> s;

	if (s == 1) {
		students.Display();
		students.BubbleSort(n);
		students.Display();
	}
	else if (s == 2) {
		students.Display();
		students.InsertionSort(n);
		students.Display();
	}
	else if (s == 3) {
		students.Display();
		students.CountingSort(n);
		students.Display();
	}
	else {
		cout << "Invalid input \n";
	}


	return 0;
}