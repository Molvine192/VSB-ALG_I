#include "BSTree.h"
#include <iostream>
#include <algorithm>
using namespace std;

void BSTree::insertValue(int value)
{
	this->insertValue(value, this->root);
}

void BSTree::insertValue(int value, Node*& root)
{
	if (root == nullptr)
	{
		root = new Node(value);
		return;
	}

	if (value < root->value)
		insertValue(value, root->left);

	if (value > root->value)
		insertValue(value, root->right);
}

bool BSTree::findValue(int value)
{
	return this->findValue(value, this->root);
}

bool BSTree::findValue(int value, Node* root)
{
	if (root == nullptr)
		return false;

	if (root->value == value)
		return true;

	if (value < root->value)
		return findValue(value, root->left);

	if (value > root->value)
		return findValue(value, root->right);
}

int BSTree::countNodes()
{
	return this->countNodes(this->root);
}

int BSTree::countNodes(Node* root)
{
	return (root == nullptr) ? 0 : 1 + countNodes(root->left) + countNodes(root->right);
}

int BSTree::height()
{
	return this->height(this->root);
}

int BSTree::height(Node* root)
{
	if (root == nullptr)
		return 0;

	return 1 + max(height(root->left), height(root->right));
}

bool BSTree::isBalanced()
{
	return this->isBalanced(this->root);
}

bool BSTree::isBalanced(Node* root)
{
	if (root == nullptr)
		return true;

	return (height(root->left) == height(root->right));
}

void BSTree::print(bool asc)
{
	this->print(asc, this->root);
}

void BSTree::print(bool asc, Node* root)
{
	if (root == nullptr)
		return;

	print(asc, asc ? root->left : root->right);
	cout << root->value << endl;
	print(asc, asc ? root->right : root->left);
}

int BSTree::countLeaves()
{
	return this->countLeaves(this->root);
}

int BSTree::countLeaves(Node* root)
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return 1;
	else
		return countLeaves(root->left) + countLeaves(root->right);
}