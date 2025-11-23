#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool dvisited[1001];
bool bvisited[1001];

void dfs(int st)
{
	dvisited[st] = true;
	cout << st << " ";

	for (int next : graph[st])
	{
		if (!dvisited[next]) dfs(next);
	}
}

void bfs(int st)
{
	queue<int> q;
	q.push(st);
	bvisited[st] = 1;

	while (!q.empty())
	{
		int node = q.front();
		cout << node << " ";
		q.pop();

		for (int next : graph[node])
		{
			if (!bvisited[next])
			{
				bvisited[next] = 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int el1, el2;
		cin >> el1 >> el2;
		graph[el1].push_back(el2);
		graph[el2].push_back(el1);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << "\n";
	bfs(v);

	return 0;
}