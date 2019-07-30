#include <iostream>
using namespace std;

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
void preOrder(Node* root) {
	if (root != NULL) {
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}


int main() {
	Node* root = NULL;


	root = add(root, 10);
	root = add(root, 20);
	root = add(root, 30);
	root = add(root, 40);
	root = add(root, 50);
	root = add(root, 25);

	/* The constructed AVL Tree would be
				30
			/ \
			20 40
			/ \ \
		10 25 50
	*/
	cout << "Preorder traversal of the "
		"constructed AVL tree is \n";
	preOrder(root);

	return 0;
}
