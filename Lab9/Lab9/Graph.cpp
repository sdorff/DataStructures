#include <iostream>
using namespace std;

//node struct
struct node {
	int value;
	struct node* next;
};

class Graph { 
public:
	int n;
	struct node** vals;
	//constructor
	Graph(int n) {
		this->n = n;
		vals = new struct node* [n];
		for (int i = 0; i < n; i++)
			vals[i] = NULL;
	}
	//adds edge to graph
	void addEdge(int x, int y) {

		struct node* node = new struct node;
		node->value = y;
		node->next = NULL;
		struct node* curr = vals[x];

		if (curr == NULL) {
			vals[x] = node;
		}
		else {

			while (curr->next != NULL) {
				curr = curr->next;
			}
			curr->next = node;
		}

	}

	//removes edge
	void removeEdge(int x, int y) {
		struct node* curr = vals[x];
		struct node* previous = curr;
		while (curr->value != y) {
			previous = curr;
			curr = curr->next;
		}
		previous->next = curr->next;
		delete curr;
	}
	//return true or false if edge exists
	bool hasEdge(int x, int y) {
		struct node* curr = vals[x];
		while (curr != NULL && curr->value != y) {
			curr = curr->next;
		}
		return curr != NULL;
	}
	//list of out edges
	struct node* outEdges(int x) {
		return vals[x];
	}
	//check for in edges
	struct node* inEdges(int y) {
		struct node* head = NULL;
		struct node* curr = NULL;
		for (int j = 0; j < n; j++) {
			if (hasEdge(j, y)) {
				if (head == NULL) {
					head = new struct node;
					head->value = j;
					head->next = NULL;
					curr = head;
				}
				else {
					curr->next = new struct node;
					curr = curr->next;
					curr->value = j;
					curr->next = NULL;
				}
			}
		}
		return head;
	}
	//display the graph based on vertices
	void printGraph() {
		for (int i = 0; i < n; ++i) {
			cout << "\n List for vertex: " << i << "\n head ";
			struct node* curr = vals[i];
			if (vals[i] == NULL) {
				continue;
			}
			while (curr != NULL) {
				cout << "-> " << curr->value;
				curr = curr->next;
			}
			cout << "\n";
		}
	}
	//destructor
	~Graph() {
		struct node* curr = new struct node;

		for (int i = 0; i < n; i++) {
			curr = vals[i];

			while (curr->next != NULL) {
				struct node* temp = curr;
				curr = curr->next;
				delete temp;
			}
		}

		delete vals;
	}

};

int main() {
	Graph* g = new Graph(50);
	/*int x, y, c, l = 1;
	while (l != 0) {
		cout << "Enter 1 to add an edge \nEnter 2 to remove an edge \nEnter 3 to find an edge \nEnter 4 to find out edges \nEnter 5 to find the in edges \nEnter 6 to exit program \n";
		cin >> c;
		switch (c) {
		case 1:
			cout << "Vertex value: ";
			cin >> x;
			cout << "Connection value: ";
			cin >> y;
			g->addEdge(x, y);
			break;
		case 2:
			cout << "Vertex value: ";
			cin >> x;
			cout << "Connection value: ";
			cin >> y;
			g->removeEdge(x, y);
			break;
		case 3:
			cout << "Vertex value: ";
			cin >> x;
			cout << "Connection value: ";
			cin >> y;
			cout << g->hasEdge(x, y) << endl;
			break;
		case 4:
			cout << "Out edge: ";
			cin >> x;
			cout << g->outEdges(x) << endl;
			break;
		case 5:
			cout << "In edge: ";
			cin >> y;
			cout << g->inEdges(y) << endl;
			break;
		case 6:
			l = 0;
			break;
		}
	}*/


	g->addEdge(0, 41);
	g->addEdge(0, 9);
	g->addEdge(0, 23);
	g->addEdge(0, 8);
	g->addEdge(2, 4);
	g->addEdge(2, 27);
	g->addEdge(2, 30);
	g->addEdge(2, 40);
	g->addEdge(3, 17);
	g->addEdge(3, 24);
	g->addEdge(3, 41);
	g->addEdge(3, 35);
	g->addEdge(3, 42);
	g->addEdge(3, 23);
	g->addEdge(4, 2);
	g->addEdge(4, 27);
	g->addEdge(4, 36);
	g->addEdge(5, 43);
	g->addEdge(5, 49);
	g->addEdge(5, 26);
	g->addEdge(5, 15);
	g->addEdge(5, 35);
	g->addEdge(5, 30);
	g->addEdge(6, 38);
	g->addEdge(6, 31);
	g->addEdge(6, 20);
	g->addEdge(7, 19);
	g->addEdge(7, 29);
	g->addEdge(7, 37);
	g->addEdge(8, 1);
	g->addEdge(8, 9);
	g->addEdge(9, 8);
	g->addEdge(9, 39);
	g->addEdge(9, 32);
	g->addEdge(9, 41);
	g->addEdge(9, 1);
	g->addEdge(11, 46);
	g->addEdge(11, 36);
	g->addEdge(11, 27);
	g->addEdge(11, 43);
	g->addEdge(11, 49);
	g->addEdge(11, 25);
	g->addEdge(12, 13);
	g->addEdge(12, 16);
	g->addEdge(12, 24);
	g->addEdge(12, 14);
	g->addEdge(12, 48);
	g->addEdge(13, 34);
	g->addEdge(13, 16);
	g->addEdge(13, 12);
	g->addEdge(13, 21);
	g->addEdge(14, 12);
	g->addEdge(14, 24);
	g->addEdge(14, 26);
	g->addEdge(14, 40);
	g->addEdge(14, 22);
	g->addEdge(14, 48);
	g->addEdge(15, 24);
	g->addEdge(15, 35);
	g->addEdge(15, 5);
	g->addEdge(15, 26);
	g->addEdge(16, 34);
	g->addEdge(16, 13);
	g->addEdge(16, 12);
	g->addEdge(16, 24);
	g->addEdge(16, 41);
	g->addEdge(16, 45);
	g->addEdge(16, 47);
	g->addEdge(17, 23);
	g->addEdge(17, 3);
	g->addEdge(17, 42);
	g->addEdge(18, 28);
	g->addEdge(19, 7);
	g->addEdge(19, 37);
	g->addEdge(19, 47);
	g->addEdge(19, 45);
	g->addEdge(20, 38);
	g->addEdge(20, 6);
	g->addEdge(20, 28);
	g->addEdge(20, 44);
	g->addEdge(20, 31);
	g->addEdge(21, 34);
	g->addEdge(21, 13);
	g->addEdge(21, 48);
	g->addEdge(22, 48);
	g->addEdge(22, 14);
	g->addEdge(22, 40);
	g->addEdge(22, 33);
	g->addEdge(23, 1);
	g->addEdge(23, 3);
	g->addEdge(23, 41);
	g->addEdge(23, 17);
	g->addEdge(24, 12);
	g->addEdge(24, 16);
	g->addEdge(24, 41);
	g->addEdge(24, 3);
	g->addEdge(24, 35);
	g->addEdge(24, 15);
	g->addEdge(24, 26);
	g->addEdge(24, 14);
	g->addEdge(25, 11);
	g->addEdge(25, 49);
	g->addEdge(25, 40);
	g->addEdge(25, 33);
	g->addEdge(26, 24);
	g->addEdge(26, 15);
	g->addEdge(26, 5);
	g->addEdge(26, 49);
	g->addEdge(26, 40);
	g->addEdge(26, 14);
	g->addEdge(27, 4);
	g->addEdge(27, 36);
	g->addEdge(27, 11);
	g->addEdge(27, 43);
	g->addEdge(27, 2);
	g->addEdge(28, 18);
	g->addEdge(28, 44);
	g->addEdge(28, 20);
	g->addEdge(29, 37);
	g->addEdge(29, 31);
	g->addEdge(29, 7);
	g->addEdge(30, 42);
	g->addEdge(30, 2);
	g->addEdge(30, 5);
	g->addEdge(30, 35);
	g->addEdge(31, 44);
	g->addEdge(31, 20);
	g->addEdge(31, 6);
	g->addEdge(31, 29);
	g->addEdge(31, 37);
	g->addEdge(32, 45);
	g->addEdge(32, 39);
	g->addEdge(32, 9);
	g->addEdge(32, 41);
	g->addEdge(33, 25);
	g->addEdge(33, 22);
	g->addEdge(33, 40);
	g->addEdge(34, 37);
	g->addEdge(34, 47);
	g->addEdge(34, 16);
	g->addEdge(34, 13);
	g->addEdge(34, 21);
	g->addEdge(35, 24);
	g->addEdge(35, 3);
	g->addEdge(35, 42);
	g->addEdge(35, 30);
	g->addEdge(35, 5);
	g->addEdge(35, 15);
	g->addEdge(36, 46);
	g->addEdge(36, 11);
	g->addEdge(36, 4);
	g->addEdge(36, 27);
	g->addEdge(37, 31);
	g->addEdge(37, 29);
	g->addEdge(37, 7);
	g->addEdge(37, 19);
	g->addEdge(37, 47);
	g->addEdge(37, 34);
	g->addEdge(38, 20);
	g->addEdge(38, 6);
	g->addEdge(39, 32);
	g->addEdge(39, 9);
	g->addEdge(40, 49);
	g->addEdge(40, 25);
	g->addEdge(40, 33);
	g->addEdge(40, 22);
	g->addEdge(40, 14);
	g->addEdge(40, 26);
	g->addEdge(41, 16);
	g->addEdge(41, 45);
	g->addEdge(41, 32);
	g->addEdge(41, 9);
	g->addEdge(41, 1);
	g->addEdge(41, 23);
	g->addEdge(41, 3);
	g->addEdge(41, 24);
	g->addEdge(42, 17);
	g->addEdge(42, 3);
	g->addEdge(42, 35);
	g->addEdge(42, 30);
	g->addEdge(43, 2);
	g->addEdge(43, 27);
	g->addEdge(43, 11);
	g->addEdge(43, 49);
	g->addEdge(43, 5);
	g->addEdge(44, 31);
	g->addEdge(44, 28);
	g->addEdge(44, 20);
	g->addEdge(45, 16);
	g->addEdge(45, 47);
	g->addEdge(45, 19);
	g->addEdge(45, 32);
	g->addEdge(45, 41);
	g->addEdge(46, 36);
	g->addEdge(46, 11);
	g->addEdge(47, 34);
	g->addEdge(47, 37);
	g->addEdge(47, 19);
	g->addEdge(47, 45);
	g->addEdge(47, 16);
	g->addEdge(48, 22);
	g->addEdge(48, 21);
	g->addEdge(48, 12);
	g->addEdge(48, 14);
	g->addEdge(49, 11);
	g->addEdge(49, 25);
	g->addEdge(49, 40);
	g->addEdge(49, 26);
	g->addEdge(49, 5);
	g->addEdge(49, 43);

	cout << "Fifty states Graph with numbers coresponding in alphebetical order \n";
	g->printGraph();

	return 0;
}