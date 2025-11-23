#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
bool visited[101];

int bfs(int node)
{
	int cnt = 0;
	queue<int> q;
	q.push(node);
	visited[node] = 1;

	while (!q.empty())
	{
		node = q.front();
		q.pop();

		for (int next : graph[node])
		{
			if (visited[next]) continue;
			cnt++;
			q.push(next);
			visited[next] = 1;
		}
	}

	return cnt;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	cout << bfs(1);
	return 0;
}