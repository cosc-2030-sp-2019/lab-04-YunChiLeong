// Yun Chi Leong
// COSC 2030-01 Spring 2019
// 11 March 2019
// Binary Tree

#include <iostream>

using namespace std;


struct Node {
	int value;
	Node *left;
	Node *right;
};

class bintree {
public:
	bintree();
	~bintree();

	void insert(int key);
	Node *search(int key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();

private:
	void destroy_tree(Node *leaf);
	void insert(int key, Node *leaf);
	Node *search(int key, Node *leaf);
	void inorder_print(Node *leaf);
	void postorder_print(Node *leaf);
	void preorder_print(Node *leaf);

	Node *root;
};


bintree::bintree() {
	root = NULL;
}

bintree::~bintree() {
	destroy_tree();
}

void bintree::destroy_tree(Node *leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void bintree::insert(int key, Node *leaf) {

	if (key < leaf->value) {
		if (leaf->left != NULL) {
			insert(key, leaf->left);
		}
		else {
			leaf->left = new Node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->value) {
		if (leaf->right != NULL) {
			insert(key, leaf->right);
		}
		else {
			leaf->right = new Node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

void bintree::insert(int key) {
	if (root != NULL) {
		insert(key, root);
	}
	else {
		root = new Node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

Node *bintree::search(int key, Node *leaf) {
	if (leaf != NULL) {
		if (key == leaf->value) {
			return leaf;
		}
		if (key < leaf->value) {
			return search(key, leaf->left);
		}
		else {
			return search(key, leaf->right);
		}
	}
	else {
		return NULL;
	}
}

Node *bintree::search(int key) {
	return search(key, root);
}

void bintree::destroy_tree() {
	destroy_tree(root);
}

void bintree::inorder_print() {
	inorder_print(root);
	cout << "\n";
}

void bintree::inorder_print(Node *leaf) {
	if (leaf != NULL) {
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void bintree::postorder_print() {
	postorder_print(root);
	cout << "\n";
}

void bintree::postorder_print(Node *leaf) {
	if (leaf != NULL) {
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

void bintree::preorder_print() {
	preorder_print(root);
	cout << "\n";
}

void bintree::preorder_print(Node *leaf) {
	if (leaf != NULL) {
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}

int main() {

	//bintree tree;
	bintree *tree = new bintree();

	tree->insert(8);
	tree->insert(15);
	tree->insert(10);
	tree->insert(4);
	tree->insert(5);
	tree->insert(1);
	tree->insert(7);
	tree->insert(9);

	tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();

	delete tree;
	system("pause");
	return 0;
}