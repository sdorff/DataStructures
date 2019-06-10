#include <iostream>
#include "LinkedList.h"
#include "Node.h"

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