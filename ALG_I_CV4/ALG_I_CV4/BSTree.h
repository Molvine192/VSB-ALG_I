#pragma once

class BSTree
{
public:
	class Node
	{
	public:
		int value;
		Node* left = nullptr;
		Node* right = nullptr;

		Node(int value)
		{
			this->value = value;
		}
	};

	Node* root = nullptr;

	void insertValue(int value);
	void insertValue(int value, Node*& root);

	bool findValue(int value);
	bool findValue(int value, Node* root);

	int countNodes();
	int countNodes(Node* root);

	bool isBalanced();
	bool isBalanced(Node* root);

	int height();
	int height(Node* root);

	void print(bool asc = true);
	void print(bool asc, Node* root);

	int countLeaves();
	int countLeaves(Node* root);
};