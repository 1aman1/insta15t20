#include <iostream>
#include <vector>
#include <iterator>
#include <queue>

/*
1-> implement Graph using array of vector
*/

struct Graph
{
public:
	typedef std::vector<int> graph_t;

protected:
	graph_t *_graph;
	int vertices;

public:
	void
	print();

	void
	add_edge(int, int);

	Graph(int v) : vertices(v)
	{
		_graph = new graph_t[vertices];
	}

	~Graph()
	{
		delete[] _graph;
	}
};

void Graph::print()
{
	for (int node = 0; node < vertices; ++node)
	{
		std::cout << "vertex : " << node << " : ";
		{
			// traverse neighbour for the current vertex
			std::cout << "[ ";
			for (auto node_neighbrs = _graph[node].begin(); node_neighbrs != _graph[node].end(); ++node_neighbrs)
			{
				std::cout << *node_neighbrs << ", ";
			}
			std::cout << " ]" << std::endl;
		}
	}
}

void Graph::add_edge(int u, int v)
{
	// undirected Graph
	_graph[u].push_back(v);

	// directed Graph
	// _graph[v].push_back(u);
}

int main()
{
	Graph go(6);

	go.add_edge(0, 1);
	go.add_edge(0, 4);
	go.add_edge(0, 5);

	go.add_edge(1, 3);
	go.add_edge(1, 4);

	go.add_edge(2, 1);

	go.add_edge(3, 2);
	go.add_edge(3, 4);

	go.print();

	return 0;
}