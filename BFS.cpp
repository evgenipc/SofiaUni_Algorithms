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
#include<queue>

void BFS(const std::vector<std::vector<int>> graph,const int starting_node)
{
	bool* checked = new bool[graph.size()]{ 0 };

	std::queue<int> queue;

	queue.push(starting_node);
	checked[starting_node] = true;

	while (!queue.empty())
	{
		std::cout << queue.front() << " ";

		for (size_t i = 0; i < graph[queue.front()].size(); i++)
		{
			if (!checked[graph[queue.front()][i]])
			{
				queue.push(graph[queue.front()][i]);
				checked[graph[queue.front()][i]] = true;
			}
				
		}
		queue.pop();
	}

}


int main()
{	

	int v,e;
	std::cin >> v >> e;

	std::vector <std::vector<int>> graph(v);

	for (size_t i = 0; i < e; i++)
	{
		int from, to;
		std::cin >> from >> to;
		graph[from].push_back(to);
	}

	BFS(graph, 1);

	return 0;
}
