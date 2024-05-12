#include <iostream>
#include "BSTree.h"

using namespace std;

int main()
{
	BSTree tree;

	tree.insertValue(5);
	tree.insertValue(1);
	tree.insertValue(10);
	tree.insertValue(0);
	tree.insertValue(3);
	tree.insertValue(8);
	tree.insertValue(15);
	tree.insertValue(6);

	cout << tree.countLeaves() << endl;

	return 0;
}