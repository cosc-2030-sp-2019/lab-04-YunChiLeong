// Yun Chi Leong
// COSC 2030-01 Spring 2019
// 11 March 2019

#include <iostream> 
#include <queue> 
using namespace std;

/* A binary tree node has key, pointer to left child
and a pointer to right child */
struct Node {
	int key;
	struct Node* left, *right;
};

/* function to create a new node of tree and r
eturns pointer */
struct Node* newNode(int key)
{
	struct Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
};

// Inorder traversal of a binary tree
void inorder(struct Node* temp)
{
	if (!temp)
		return;
	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}
// Preorder traversal of binary tree
void preorder(struct Node* temp)
{
	if (!temp)
		return;
	cout << temp->key << " ";
	preorder(temp->left);
	preorder(temp->right);
}
// Postorder traversal of a binary tree
void postorder(struct Node* temp)
{
	if (!temp)
		return;
	preorder(temp->left);
	preorder(temp->right);
	cout << temp->key << " ";
}

// Driver code 
int main()
{
	struct Node* root = newNode(5);
	root->left = newNode(4);
	root->left->left = newNode(10);
	root->left->left->right = newNode(15);
	root->left->left->right->left = newNode(8);
	root->right = newNode(1);
	root->right->right = newNode(7);
	root->right->right-> right= newNode(9);


	cout << "Inorder traversal : ";
	inorder(root);
	cout << endl;
	cout << "Preorder traversal : ";
	preorder(root);
	cout << endl;
	cout << "Postorder traversal : ";
	postorder(root);
	cout << endl;
	system("pause");
	return 0;
}
