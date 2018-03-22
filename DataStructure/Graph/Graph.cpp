#include "Graph.h"

/* Graph_List */
Graph::Graph()
{
	graph = NULL;
	VertexCount = 0;
}

Graph::~Graph()
{
	while (graph != NULL)
	{
		Vertex* vertex = graph->next;
		DeleteVertex(graph);
		graph = vertex;
	}
}

void Graph::AddVertex(int data)
{
	if (graph)
	{
		Vertex* PreviousVertex = graph;
		Vertex* NextVertex = graph->next;

		while (NextVertex != NULL)
		{
			PreviousVertex = NextVertex;
			NextVertex = NextVertex->next;
		}

		NextVertex = new Vertex();
		NextVertex->data = data;
		PreviousVertex->next = NextVertex;
	}
	else
	{
		graph = new Vertex();
		graph->data = data;
	}

	VertexCount++;
}

void Graph::AddEdge(Vertex* from, Vertex* target)
{
	if (from && target)
	{
		if (from->AdjacencyList)
		{
			Edge* PreviousEdge = from->AdjacencyList;
			Edge* NextEdge = from->AdjacencyList->next;

			while (NextEdge != NULL)
			{
				PreviousEdge = NextEdge;
				NextEdge = NextEdge->next;
			}

			NextEdge = new Edge();
			NextEdge->from = from;
			NextEdge->target = target;
			PreviousEdge->next = NextEdge;
		}
		else
		{
			from->AdjacencyList = new Edge();
			from->AdjacencyList->from = from;
			from->AdjacencyList->target = target;
		}
	}
}

void Graph::DeleteVertex(Vertex* vertex)
{
	while (vertex->AdjacencyList != NULL)
	{
		Edge* edge = vertex->AdjacencyList->next;
		DeleteEdge(vertex->AdjacencyList);
		vertex->AdjacencyList = edge;
	}

	delete vertex;
}

void Graph::DeleteEdge(Edge* edge)
{
	delete edge;
	edge = NULL;
}

void Graph::DeleteVisit()
{
	Vertex* vertex = graph;

	while (vertex != NULL)
	{
		vertex->Visited = false;
		vertex = vertex->next;
	}
}

void Graph::PrintGraph()
{
	Vertex* vertex = graph;

	while (vertex != NULL)
	{
		Edge* edge = vertex->AdjacencyList;
		cout << vertex->data << " : ";

		while (edge != NULL)
		{
			cout << edge->target->data << " ";
			edge = edge->next;
		}

		vertex = vertex->next;
		cout << endl;
	}
}

Vertex* Graph::SearchVertex(int data)
{
	if (graph)
	{
		Vertex* vertex = graph;

		while (vertex != NULL)
		{
			if (vertex->data == data)
				return vertex;
			vertex = vertex->next;
		}

		return NULL;
	}
}

void Graph::Traversal(int Select)
{
	if (Select == 1)
		DFS(graph);
	else
		BFS(graph);

	DeleteVisit();
}

void Graph::DFS(Vertex* vertex)
{
	Edge* edge = vertex->AdjacencyList;
	vertex->Visited = true;
	cout << "-> " << vertex->data << " ";

	while (edge)
	{
		if (!edge->target->Visited)
			DFS(edge->target);
		else
			return;

		edge = edge->next;
	}
}

void Graph::BFS(Vertex* vertex)
{
	CircularQueue queue(10);
	queue.EnQueue(vertex->data);
	vertex->Visited = true;

	while (!queue.Empty())
	{
		vertex = SearchVertex(queue.DeQueue());
		Edge* edge = vertex->AdjacencyList;
		cout << "-> " << vertex->data << " ";

		while (edge != NULL)
		{
			if (!edge->target->Visited)
			{
				queue.EnQueue(edge->target->data);
				edge->target->Visited = true;
			}
			edge = edge->next;
		}
	}
}


/* Graph_Vector */
Graph_vector::Graph_vector(int capacity)
{
	Graph.reserve(capacity);
}

Graph_vector::~Graph_vector()
{
	vector<vector<int> > TempRows;

	for (int i = 0; i < VertexCount; i++)
	{
		vector<int> TempCols;

		Graph[i].clear();
		Graph[i].swap(TempCols);
	}

	Graph.clear();
	Graph.swap(TempRows);
}

void Graph_vector::AddVertex(int data)
{
	vector<int> v(1, data);
	Graph.push_back(v);
	VertexCount++;
}

void Graph_vector::AddEdge(int from, int target)
{
	if (from >= 0 && target >= 0)
		Graph[from].push_back(Graph[target][0]);
}

int Graph_vector::SearchVertex(int data)
{
	for (int index = 0; index < VertexCount; index++)
	{
		if (Graph[index][0] == data)
			return index;
	}
	return -1;
}

void Graph_vector::PrintGraph()
{
	for (int i = 0; i < VertexCount; i++)
	{
		cout << Graph[i][0] << " : ";
		for (int j = 1; j < Graph[i].size(); j++)
			cout << Graph[i][j] << " ";
		cout << endl;
	}
}