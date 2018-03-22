/*
	Input :  num of vertices, num of edges that follow
	edges are pairs of 2 ints denoting FROM and TO vertices that are connected
	sample input:
		5 5	
		1 2
		1 3
		3 4
		2 0
		2 1
*/

#include<iostream>
#include<vector>

void DFS(const std::vector<std::vector<int>>& graph, bool * const checked, const int current_vertex)
{
	std::cout << current_vertex << " ";
	checked[current_vertex] = true;
	for (size_t i = 0; i < graph[current_vertex].size(); i++)
	{
		if (!checked[graph[current_vertex][i]])
		{
			DFS(graph, checked, graph[current_vertex][i]);
		}
	}	
}

int main()
{
	int v, e;
	std::cin >> v >> e;

	std::vector<std::vector<int>> graph(v);

	for (size_t i = 0; i < e; i++)
	{
		int from, to;
		std:: cin >> from >> to;
		graph[from].push_back(to);
	}

	bool* checked = new bool[v] {0};
	DFS(graph, checked, 1);

	return 0;
}
