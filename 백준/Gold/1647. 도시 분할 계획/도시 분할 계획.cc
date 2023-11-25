#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// kruskal 구조체
struct graph
{
	int from, to, cost;
	bool operator < (const graph& other) const
	{
		return cost < other.cost;
	}
};

int parent[100001];

int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = parent[x];
	y = parent[y];
	
	if (x == y) return;
	
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

bool UnionCheck(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y) return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	int a, b;
	scanf("%d %d", &a, &b);

	// Init
	for (int i = 1; i <= a; i++)
	{
		parent[i] = i;
	}

	vector<graph> v(b);
	for (int i = 0; i < b; i++)
	{
		scanf("%d %d %d", &v[i].from, &v[i].to, &v[i].cost);
	}

	sort(v.begin(), v.end());

	// Union/Find
	int cnt = 0;
	int w;
	for (int i = 0; i < b; i++)
	{
		if (!UnionCheck(v[i].from, v[i].to))
		{
			Union(v[i].from, v[i].to);
			cnt += v[i].cost;
			w = v[i].cost;
		}
	}

	printf("%d", cnt-w);
	return 0;
}