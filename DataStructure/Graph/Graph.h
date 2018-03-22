#pragma once
#include <iostream>
#include <vector>
#include "Queue.h"
using namespace std;

struct Edge;
struct Vertex
{
	int data;
	bool Visited;
	Vertex* next;
	Edge* AdjacencyList;
};

struct Edge
{
	Vertex* from;
	Vertex* target;
	Edge* next;
};


class Graph
{
private:
	Vertex* graph;
	int VertexCount;
	/* Delete */
	void DeleteVertex(Vertex* vertex);
	void DeleteEdge(Edge* edge);
	void DeleteVisit();
	/* Travarsal */
	void DFS(Vertex* vertex);
	void BFS(Vertex* vertex);
public:
	Graph();
	~Graph();
	void AddVertex(int data);
	void AddEdge(Vertex* from, Vertex* target);
	void PrintGraph();
	Vertex* SearchVertex(int data);
	/* Select Traversal ? 1 : DFS, 2 : BFS */
	void Traversal(int Select = 1);
};

class Graph_vector
{
private:
	vector<vector<int> > Graph;
	int VertexCount;
public:
	Graph_vector(int = 10);
	~Graph_vector();
	void AddVertex(int data);
	void AddEdge(int from, int target);
	void PrintGraph();
	int SearchVertex(int data);
};