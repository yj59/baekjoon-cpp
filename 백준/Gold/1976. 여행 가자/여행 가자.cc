#include <iostream>
using namespace std;

int plan[1001];
bool graph[201][201] = { 0, };
int parent[201];


int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	int px = Find(parent[x]);
	int py = Find(parent[y]);

	// cout << x << "'s parent is " << px << "\n";
	if (px == py) return;
	if (px < py) parent[py] = px;
	else parent[px] = py;
}

int main()
{
	int n, m;
	cin >> n >> m;

	// init
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	// 그래프 입력 + Union
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 1)
			{
				Union(i, j);
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> plan[i];
	}

	// Find
	int route = Find(parent[plan[0]]);

	for (int i = 0; i < m; i++)
	{
		int route_ = Find(parent[plan[i]]);
		if (route != route_)
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}