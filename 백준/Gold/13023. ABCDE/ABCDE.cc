#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> graph[2001];
bool visited[2001];
int n, m;

bool solve(int depth, int num)
{
	if (depth == 5)
	{
		return true;
	}

	for (int i = 0; i < graph[num].size(); i++)
	{
		int node = graph[num][i];

		if (visited[node]) continue;

		visited[node] = 1;
		if (solve(depth + 1, node)) return 1;
		visited[node] = 0;
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < n; i++)
	{
		visited[i] = 1;
		if (solve(1, i))
		{
			cout << 1;
			return 0;
		}
		visited[i] = 0;
	}

	cout << 0;
	return 0;
}