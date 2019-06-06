#include <iostream>
 
using namespace std;



class List {
private:
	struct Student {
		int MNumber;
		string firstName;
		string lastName;
		string birthday;
		float gpa;
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
	void AddItem(int m, string f, string l, string b, float g) {
		Student* n = new Student;
		n->next = NULL;
		n->MNumber = m;
		n->firstName = f;
		n->lastName = l;
		n->birthday = b;
		n->gpa = g;
		if (head == NULL) {
			head = n;
		}
		else if(m < head->MNumber){
			n->next = head;
			head = n;
			track = head;
		}
		else {
			current = head;
			while (current->next != NULL && current->next->MNumber < m) {
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

	void Display() {
		current = head;
		while (current) {
			cout << current->MNumber << "->";
			current = current->next;
		}
		cout << "X" << endl;
	}

};

int main() {
	List students;
	int c = 1;//tracks usage of class
	int n;
	int mNumber;
	string firstName;
	string lastName;
	string birthday;
	float gpa;
	int location;

	while (c != 0) {
		cout << "Choose the number of what method you want to use: \n0. Exits the program \n1. Add an item \n2. Get an item \n3. See if an item is in the list \n4. See if the list is empty \n5. See the size off the list \n6. Use the SeeNext method \n7. See which item is in a certain position \n8. Reset the SeeNext method \n9. Display the list \n";
		cin >> n;

		//stops the program
		if (n == 0) {
			break;
		}
		//adds item to list
		else if (n == 1) {
			cout << "You have chosen to add an item" << endl;
			cout << "What is the MNumber without the M: " << endl;
			cin >> mNumber;
			cout << "What is the first name: " << endl;
			cin >> firstName;
			cout << "What is the last name: " << endl;
			cin >> lastName;
			cout << "What is the birthday: " << endl;
			cin >> birthday;
			cout << "What is the gpa: " << endl;
			cin >> gpa;
			students.AddItem(mNumber, firstName, lastName, birthday, gpa);
		}
		//removes an item
		else if (n == 2) {
			cout << "What is the M number of the student: " << endl;
			cin >> mNumber;
			cout << "Your item is " << students.GetItem(mNumber) << endl;
		}
		//returns if a student is in the list
		else if (n == 3) {
			cout << "What is the M number: " << endl;
			cin >> mNumber;
			cout << students.IsInList(mNumber) << endl;
		}
		//checks if the list is empty
		else if (n == 4) {
			cout << students.IsEmpty() << endl;
		}
		//retuns the size of the list
		else if (n == 5) {
			cout << "The list is " << students.Size() << " items big" << endl;
		}
		//returns an item in the list
		else if (n == 6) {
			cout << "Your item is " << students.SeeNext() << endl;
		}
		//finds item at a certain location
		else if (n == 7) {
			cout << "What location do you want to search? " << endl;
			cin >> location;
			cout << "Item " << students.SeeAt(location) << " is at your location " << endl;
		}
		//resets the seenext funciton
		else if (n == 8) {
			students.Reset();
			cout << "The list has been reset" << endl;
		}
		//displays the list
		else if (n == 9) {
			students.Display();
		}
		//re promts the user
		else {
			cout << "Your input value must be between 0 and 8";
		}
	}

	return 0;
}