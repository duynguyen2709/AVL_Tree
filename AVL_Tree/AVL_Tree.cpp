#include "AVL_Tree.h"

int AVL_Tree::max(const int a, const int b)
{
	return (a > b) ? a : b;
}

int AVL_Tree::getBalance(const Node * node)
{
	if (node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}

int AVL_Tree::height(const Node * node)
{
	if (node==NULL)
		return 0;
	return node->height;
}

Node * AVL_Tree::rightRotate(Node * root)
{
	Node *x = root->left;
	Node *T2 = x->right;

	x->right = root;
	root->left = T2;

	root->height = max(height(root->left), height(root->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

Node * AVL_Tree::leftRotate(Node * root)
{
	struct Node *y = root->right;
	struct Node *T2 = y->left;

	y->left = root;
	root->right = T2;

	root->height = max(height(root->left), height(root->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

Node * AVL_Tree::minValueNode(Node * node)
{
	Node* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

AVL_Tree::AVL_Tree()
{
	root = NULL;
}

AVL_Tree::~AVL_Tree()
{
	delete root;
}

Node* AVL_Tree::insert(Node* node, int key)
{
	if (node == NULL)
		return new Node(key);
	

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else 
		return node;

	node->height = 1 + max(height(node->left),
		height(node->right));

	int balance = getBalance(node);

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

Node* AVL_Tree::deleteNode(Node* root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else
	{
		
		if ((root->left == NULL) || (root->right == NULL))
		{
			Node *temp = root->left ? root->left : root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else 
				*root = *temp; 

			delete temp;
		}
		else
		{
			Node* temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}

	if (root == NULL)
		return root;

	root->height = 1 + max(height(root->left),
		height(root->right));

	int balance = getBalance(root);

	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

Node * AVL_Tree::search(Node * root, int key)
{
	if (root == NULL || root->key == key)
		return root;
	if (key > root->key)
		return search(root->right, key);
	return search(root->left, key);
}
