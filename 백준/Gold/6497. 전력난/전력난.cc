#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parents[200001];

struct graph
{
	int from, to, cost;
	bool operator < (const graph& other) const
	{
		return cost < other.cost;
	}
};

int Find(int x)
{
	if (parents[x] == x) return x;
	return parents[x] = Find(parents[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y) return;

	if (x < y) parents[y] = x;
	else parents[x] = y;
}

bool UnionCheck(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y) return 1;
	else return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	while (1)
	{
		int a, b;
		int total = 0;
		cin >> a >> b;
		if (a == 0 && b == 0) break;

		// Init
		for (int i = 0; i < a; i++)
		{
			parents[i] = i;
		}

		vector<graph>v(b);
		for (int i = 0; i < b; i++)
		{
			cin >> v[i].from >> v[i].to >> v[i].cost;
			total += v[i].cost;
		}
		sort(v.begin(), v.end());

		// Union&Find
		int save = 0;
		for (int i = 0; i < b; i++)
		{
			if (!UnionCheck(v[i].from, v[i].to))
			{
				Union(v[i].from, v[i].to);
				save += v[i].cost;
			}
		}

		cout << total - save << "\n";
	}
	
	return 0;
}