#include <iostream>
using namespace std;
#define COUNT 10 

class Node {
public:
	int data;
	Node* right;
	Node* left;
	int height;
};


//tree height
int height(Node* n) {
	if (n == NULL)
		return 0;
	return n->height;
}

//returns value of higher integer
int maxVal(int a, int b) {
	return (a > b) ? a : b;
}

Node* newNode(int k) {
	Node* n = new Node();

	n->data = k;
	n->left = NULL;
	n->right = NULL;
	n->height = 1;

	return(n);
}

//rotates tree right 
Node* rotateRight(Node* n) {
	Node* x = n->left;
	Node* temp = x->right;

	x->right = n;
	n->left = temp;

	n->height = maxVal(height(n->left),
		height(n->right)) + 1;
	x->height = maxVal(height(x->left),
		height(x->right)) + 1;

	return x;
}

//rotates tree right 
Node* rotateLeft(Node* n) {
	Node* x = n->right;
	Node* temp = x->left;

	x->left = n;
	n->right = temp;

	n->height = maxVal(height(n->left),
		height(n->right)) + 1;
	x->height = maxVal(height(x->left),
		height(x->right)) + 1;

	return x;
}

//returns how balanced the tree is 
int balance(Node* n) {
	if (n == NULL)
		return 0;
	return height(n->left) - height(n->right);
}

//inserts new data 
Node* add(Node* n, int k)
{
	if (n == NULL) {
		return(newNode(k));
	}

	if (k < n->data) {
		n->left = add(n->left, k);
	}
	else if (k > n->data) {
		n->right = add(n->right, k);
	}
	else {
		return n;
	}

	n->height = 1 + maxVal(height(n->left),
		height(n->right));

	int b = balance(n);

	if (b > 1 && k < n->left->data)
		return rotateRight(n);

	if (b < -1 && k > n->right->data) {
		return rotateLeft(n);
	}

	if (b > 1 && k > n->left->data) {
		n->left = rotateLeft(n->left);
		return rotateRight(n);
	}

	if (b < -1 && k < n->right->data) {
		n->right = rotateRight(n->right);
		return rotateLeft(n);
	}

	return n;
}

//prints tree
void printUsed(Node* r, int x)
{ 
	if (r == NULL)
		return;
	x += COUNT;
	printUsed(r->right, x); 
	cout << endl;

	for (int i = COUNT; i < x; i++) {
		cout << " ";
	}

	cout << r->data << endl;  
	printUsed(r->left, x);
}

void print(Node* r) {
	printUsed(r, 0);
}



void preOrder(Node* root) {
	if (root != NULL) {
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}


int main() {
	Node* root = NULL;
	int c;
	int x;
	int l = 1;
	

	while (l != 0) {
		cout << "Input the number of what action you want to perform: " << endl;
		cout << "1. Add item to the tree \n2. Remove item from the tree \n3. Print tree \n4. Exit the program \n";
		cin >> c;
		if (c == 1) {
			cout << "Enter the integer you would like to add to the tree: " << endl;
			cin >> x;
			root = add(root, x);
		}
		else if (c == 2) {

		}
		else if (c == 3) {
			print(root);
		}
		else if (c == 4) {
			l = 0;
		}
		else {
			cout << "Invalid input." << endl;
		}
	}
	

	return 0;
}
