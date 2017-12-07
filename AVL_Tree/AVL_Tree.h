#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node *left;
	Node *right;
	int height;
	Node(int _key)
	{
		key = _key;
		left = right = NULL;
		height = 1;
	}
};

class AVL_Tree
{
private :

	int max(const int a, const int b);

	int getBalance(const Node *node);

	int height(const Node *node);

	Node * rightRotate(Node *root);

	Node * leftRotate(Node * root);

	Node * minValueNode(Node* node);
	

public :
	Node *root;

	AVL_Tree();

	~AVL_Tree();

	Node * insert(Node *node, int key);

	Node * deleteNode(Node *root, int key);

	Node * search(Node *root, int key);
};
