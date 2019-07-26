#include<iostream>
#include<stdlib.h>
using namespace std;

class Node {
public:
	string k;
	Node* left;
	Node* right;

	//overload <=
	bool operator <= (Node n) {
		return k <= n.k;
	}
	//overload >=
	bool operator >= (Node n) {
		return k >= n.k;
	}
	//overload ==
	bool operator == (Node n) {
		return k == n.k;
	}
	//overload <
	bool operator < (Node n) {
		return k < n.k;
	}
};


//binary tree class
class BinaryTree {
private:
	//initializes root of tree
	Node* root;

	//inserts node into the tree
	Node* insert(Node* n, Node* m)
	{
		//used if the node is open
		if (n == NULL) {
			return m;
		}
		//inserts to the left of parent
		if (m->k < n->k) {
			n->left = insert(n->left, m);
		}
		//inserts to the right of parent
		else if (m->k > n->k) {
			n->right = insert(n->right, m);
		}

		return n;
	}

	//finds the lowest node
	Node* findMin(Node* n) {
		while (n->left) {
			n = n->left;
		}
		return n;
	}

	//deletes a specific node from the tree
	Node* deleteNode(Node* n, string k) {
		Node* temp;

		//returns null if there is no node
		if (!n) {
			return NULL;
		}
		//if the key is a leaf
		else if (n->k < k) {
			n->right = deleteNode(n->right, k);
		}
		//if the key is a leaf
		else if (n->k > k) {
			n->left = deleteNode(n->left, k);
		}
		//if the key is a parent
		else if (n->k == k) {
			//if there is no leaf on the left
			if (!n->left) {
				temp = n->right;
				delete(n);
				return temp;
			}
			//no leaf on the right
			if (!n->right) {
				temp = n->left;
				delete(n);
				return temp;
			}

			temp = findMin(n->right);
			n->k = temp->k;
			deleteNode(n->right, temp->k);
		}
		//outputs if the node isn't found
		else {
			cout << "key not found\n";
		}


		return n;
	}

	Node* search(Node* n, string k)
	{
		//returns the node if it is in the first place
		if (n == NULL || n->k == k) {
			return n;
		}
		//calls search again to move to the right of the tree
		if (n->k < k) {
			return search(n->right, k);
		}
		//calls search again to move to the left of the tree
		return search(n->left, k);
	}

	int size(Node* n) {
		if (!n) {
			return 0;
		}
		//calls till base case 0 
		return 1 + size(n->left) + size(n->right);
	}

	void increasingOrder(Node* n, string& a) {
		//base case
		if (!n) {
			return;
		}

		increasingOrder(n->left, a);
		a += n->k + "\n";
		increasingOrder(n->right, a);
	}

	void decreasingOrder(Node* n, string& a) {
		//base case
		if (!n) {
			return;
		}

		decreasingOrder(n->right, a);
		a += n->k + "\n";
		decreasingOrder(n->left, a);
	}


public:
	BinaryTree() {
		root = NULL;
	}

	void insert(string s) {
		Node* temp = new Node;
		temp->k = s;
		temp->left = NULL;
		temp->right = NULL;
		root = insert(root, temp);
	}

	void remove(string s) {
		root = deleteNode(root, s);
	}

	Node* find(string s) {
		return search(root, s);
	}

	int size() {
		return size(root);
	}

	string getAllAscending() {
		string a = "";
		increasingOrder(root, a);
		return a;
	}

	string getAllDescending() {
		string a = "";
		decreasingOrder(root, a);
		return a;
	}

};


int main()
{
	//creates the first tree
	BinaryTree tree1;
	string a1[] = { "Star Wars", "Star Trek", "Space Balls", "Galaxy Quest" };
	//inserts all items into the tree
	for (int i = 0; i < 4; i++) {
		tree1.insert(a1[i]);
	}
	//outputs the tree
	cout << "The tree has " << tree1.size() << " items \n";
	cout << "Ascending: \n" << tree1.getAllAscending() << "\n";
	cout << "Descending: \n" << tree1.getAllDescending() << "\n";

	//creates the second tree
	BinaryTree tree2;
	string a2[] = { "Cars", "Monsters, Inc", "The Incredibles", "Wall-E" };
	//inserts all items into the tree
	for (int i = 0; i < 4; i++) {
		tree2.insert(a2[i]);
	}
	//outputs the tree
	cout << "The tree has " << tree2.size() << " items \n";
	cout << "Ascending: \n" << tree2.getAllAscending() << "\n";
	cout << "Descending: \n" << tree2.getAllDescending() << "\n";

	//creates the third tree
	BinaryTree tree3;
	string a3[] = { "Halloween", "A Nightmare On Elm Street", "Hocus Pocus", "Beetlejuice" };
	//inserts all items into the tree
	for (int i = 0; i < 4; i++) {
		tree3.insert(a3[i]);
	}
	//outputs the tree
	cout << "The tree has " << tree3.size() << " items \n";
	cout << "Ascending: \n" << tree3.getAllAscending() << "\n";
	cout << "Descending: \n" << tree3.getAllDescending() << "\n";

	return 0;
}