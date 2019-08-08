#include<iostream>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

class HashTable {
private:
	string** H;
	int s;
	int l;
	int col;
	int Hash(string* str) {
		int sum = 0;
		for (int i = 0; i < str->length(); i++) {
			sum += str->at(i);
		}
		return sum % s;
	}
public:
	HashTable(int size = 100) {
		this->s = size;
		H = new string * [size];
		for (int i = 0; i < this->s; i++)
			H[i] = 0;
		l = 0;
		col = 0;
	}

	void add(string* str) {
		if (l < s) {
			int k = Hash(str);
			while (true) {
				if (H[k] == 0) {
					H[k] = str;
					l++;
					break;
				}
				else {
					k = (k + 1) % s;
					col++;
				}
			}
		}
	}

	string* del(string* str) {
		int k = Hash(str);
		string* temp;
		while (true) {
			if (*str == *H[k]) {
				temp = H[k];
				H[k] = 0;
				return temp;
			}
			else {
				k = (k + 1) % s;
				if (H[k] == 0)
					return 0;
			}
		}
	}

	string* get(string* str) {
		int k = Hash(str);
		while (true) {
			if (*str == *H[k]) {
				return H[k];
			}
			else {
				k = (k + 1) % s;
				if (H[k] == 0)
					return 0;
			}
		}
	}

	int length() {
		return l;
	}
	int size() {
		return s;
	}

	int collision() {
		return col;
	}

	~HashTable() {
		for (int i = 0; i < s; i++) {
			delete(H[i]);
		}
		delete(H);
	}

	void print() {
		cout << "Content of hash table" << endl;
		for (int i = 0; i < s; i++) {
			if (H[i] != 0)
				cout << H[i]->data() << " ";
			else
				cout << "null" << " ";
		}
	}

};


string randomString() {
	string r = "";
	int j;
	string alphanum = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 4; i++) {

		j = rand() % alphanum.length();
		r = r + alphanum.substr(j, 1);
	}
	return r;
}

void FourLetter() {
	HashTable* HT100 = new HashTable(100);
	HashTable* HT200 = new HashTable(200);
	HashTable* HT500 = new HashTable(500);

	for (int i = 0; i < 100; i++) {
		srand(i + time(0));
		string s = randomString();
		HT100->add(&s);
		HT200->add(&s);
		HT500->add(&s);
	}
	cout << setw(20) << "Table size" << setw(20) << "Number of collisions" << endl;
	cout << setw(20) << HT100->size() << setw(20) << HT100->collision() << endl;
	cout << setw(20) << HT200->size() << setw(20) << HT200->collision() << endl;
	cout << setw(20) << HT500->size() << setw(20) << HT500->collision() << endl;
}


int main() {
	HashTable* HT = new HashTable(10);
	int c;
	do {
		cout << endl;
		cout << "Select 1 to add an item" << endl;
		cout << "Select 2 to remove an item" << endl;
		cout << "Select 3 to get an item" << endl;
		cout << "Select 4 to get the length" << endl;
		cout << "Select 5 to print the hash table" << endl;
		cout << "Select 6 to exit the program" << endl;
		cout << "What is your selection: ";
		cin >> c;
		if (c == 1) {
			string* s = new string();
			cout << "Enter item name: ";
			cin >> *s;
			HT->add(s);
		}
		else if (c == 2) {
			string str;
			cout << "Enter item name: ";
			cin >> str;
			if (HT->del(&str) != 0)
				cout << "Removed" << endl;
			else
				cout << "No item" << endl;
		}
		else if (c == 3) {
			string str;
			cout << "Enter item name: ";
			cin >> str;
			if (HT->get(&str) != 0)
				cout << "Found" << endl;
			else
				cout << "No item" << endl;
		}
		else if (c == 4) {
			cout << HT->length() << endl;
		}
		else if (c == 5) {
			HT->print();
		}

	} while (c != 6);

	FourLetter();
	return 0;
}