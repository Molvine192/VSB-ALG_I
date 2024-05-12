#include "Graph.h"
#include <queue>
#include <stack>
#include <iostream>

Graph::Vertex* Graph::findVertex(int id)
{
	for (auto vertex : this->vertices)
	{
		if (vertex->id == id)
			return vertex;
	}

	return nullptr;
}

void Graph::insertVertex(int id)
{
	if (!findVertex(id))
		this->vertices.push_back(new Vertex(id));
}

void Graph::insertVertex(int id, vector<int> neighborIds)
{
	if (!findVertex(id))
	{
		Vertex* newVertex = new Vertex(id);

		this->vertices.push_back(newVertex);
		
		for (auto neighborId : neighborIds)
		{
			Vertex* neighbor = findVertex(neighborId);

			if (neighbor)
			{
				newVertex->neighbors.push_back(neighbor);
				if (newVertex != neighbor)
					neighbor->neighbors.push_back(newVertex);
			}
		}
	}
}

void Graph::BFS(Vertex* start)
{
	queue<Vertex*> que;

	que.push(start);
	start->color = 1;

	while (!que.empty())
	{
		Vertex* current = que.front();
		que.pop();
		cout << current->id << endl;
		current->color = 2;

		for (auto neighbor : current->neighbors)
		{
			if (neighbor->color == 0)
			{
				que.push(neighbor);
				neighbor->color = 1;
			}
		}
	}
}

void Graph::DFS(Vertex* start)
{
	stack<Vertex*> que;

	que.push(start);
	start->color = 1;

	while (!que.empty())
	{
		Vertex* current = que.top();
		que.pop();
		cout << current->id << endl;
		current->color = 2;

		for (auto neighbor : current->neighbors)
		{
			if (neighbor->color == 0)
			{
				que.push(neighbor);
				neighbor->color = 1;
			}
		}
	}
}