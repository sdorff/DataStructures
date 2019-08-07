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
		string str = randomString();
		HT100->add(&str);
		HT200->add(&str);
		HT500->add(&str);
	}
	cout << setw(20) << "Hash table size" << setw(20) << "No.of Collision" << endl;
	cout << setw(20) << HT100->size() << setw(20) << HT100->collision() << endl;
	cout << setw(20) << HT200->size() << setw(20) << HT200->collision() << endl;
	cout << setw(20) << HT500->size() << setw(20) << HT500->collision() << endl;
}

void WorldSeries() {

}


int main() {
	HashTable* HT = new HashTable(10);
	int option;
	do {
		cout << endl;
		cout << "1. Add Item" << endl;
		cout << "2. Remove Item" << endl;
		cout << "3. Get Item" << endl;
		cout << "4. Get Length" << endl;
		cout << "5. Print table" << endl;
		cout << "6. Quit" << endl;
		cout << "Enter choice: ";
		cin >> option;
		if (option == 1) {
			string* str = new string();
			cout << "Enter item name: ";
			cin >> *str;
			HT->add(str);
		}
		else if (option == 2) {
			string str;
			cout << "Enter item name to be removed: ";
			cin >> str;
			if (HT->del(&str) != 0)
				cout << "Item removed!" << endl;
			else
				cout << "Item not found" << endl;
		}
		else if (option == 3) {
			string str;
			cout << "Enter item name to be searched: ";
			cin >> str;
			if (HT->get(&str) != 0)
				cout << "Item found" << endl;
			else
				cout << "Item not found" << endl;
		}
		else if (option == 4) {
			cout << HT->length() << endl;
		}
		else if (option == 5) {
			HT->print();
		}

	} while (option != 6);

	FourLetter();
	WorldSeries();
	return 0;
}