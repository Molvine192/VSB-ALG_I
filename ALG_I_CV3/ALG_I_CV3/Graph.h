#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Graph
{
public:
	class Vertex
	{
	public:
		int id;
		vector<Vertex*> neighbors;
		int color = 0; // 0 - white, 1 - gray, 2 - black

		Vertex(int id)
		{
			this->id = id;
		}
	};

	vector<Vertex*> vertices;

	Vertex* findVertex(int id);
	void insertVertex(int id);
	void insertVertex(int id, vector<int> neighborIds);

	void BFS() {
		if (!this->vertices.empty())
		{
			this->BFS(this->vertices[0]);
		}
	}

	void BFS(Vertex* start);

	void DFS() {
		if (!this->vertices.empty())
		{
			this->DFS(this->vertices[0]);
		}
	}

	void DFS(Vertex* start);
};