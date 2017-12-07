#include <iostream>
#include "AVL_Tree.h"

using namespace std;

int main(int argc, char** argv)
{
	AVL_Tree *tree = new AVL_Tree();

	tree->root = tree->insert(tree->root, 9);
	tree->root = tree->insert(tree->root, 5);
	tree->root = tree->insert(tree->root, 10);
	tree->root = tree->insert(tree->root, 0);
	tree->root = tree->insert(tree->root, 6);
	tree->root = tree->insert(tree->root, 11);
	tree->root = tree->insert(tree->root, -1);
	tree->root = tree->insert(tree->root, 1);
	tree->root = tree->insert(tree->root, 2);

	tree->root = tree->deleteNode(tree->root, 10);
	
	return 0;
}
