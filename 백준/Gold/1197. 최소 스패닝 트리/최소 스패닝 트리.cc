#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> graph;
int parent[10001];

int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	int px = Find(x);
	int py = Find(y);

	if (px == py) return;

	if (px < py) parent[py] = x;
	else parent[px] = y;
}

bool UnionCheck(int x, int y)
{
	int px = Find(x);
	int py = Find(y);
	if (px == py) return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	// init
	for (int i = 1; i <= a; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < b; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph.push_back({ cost, {from, to} });
	}
	sort(graph.begin(), graph.end());

	// Union
	int cnt = 0;
	for (int i = 0; i < b; i++)
	{
		if (!UnionCheck(graph[i].second.first, graph[i].second.second))
		{
			Union(graph[i].second.first, graph[i].second.second);
			cnt += graph[i].first;
		}
	}
	cout << cnt;
	return 0;
}