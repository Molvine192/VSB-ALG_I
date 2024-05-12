#include <iostream>
#include "Graph.h"
#include <vector>
using namespace std;

int main()
{
	Graph g;

	vector<int> neighbors;

	g.insertVertex(1);

	neighbors.push_back(1);
	g.insertVertex(2, neighbors);

	neighbors.push_back(2);
	g.insertVertex(3, neighbors);

	neighbors.push_back(3);
	g.insertVertex(4, neighbors);

	neighbors.clear();
	neighbors.push_back(3);
	neighbors.push_back(4);
	g.insertVertex(5, neighbors);

	g.DFS();

	return 0;
}