#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1002];
bool visited[1002];

int n, m, st;

void input()
{
	cin >> n >> m >> st;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
}

void init()
{
	memset(visited, 0, n * sizeof(bool));
	cout << st << " ";
}

void dfs(int cnt, int node)
{
	visited[node] = 1;
	cout << node << " ";

	if (cnt == n) return;

	for (int i = 0; i < graph[node].size(); i++)
	{
		if (visited[graph[node][i]]) continue;
		dfs(cnt + 1, graph[node][i]);
	}
}

void bfs()
{
	queue<int> q;

	visited[st] = true;
	q.push(st);

	cout << "\n" << st << " ";

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int i = 0; i < graph[node].size(); i++)
		{
			int next = graph[node][i];
			if (visited[next]) continue;

			visited[next] = true;
			q.push(next);

			cout << next << " ";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	dfs(0, st);
	memset(visited, 0, sizeof(visited));
	bfs();

	return 0;
}