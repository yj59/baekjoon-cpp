#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int p[10001];
int visited[10001];

int lca(int n)
{
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		p[b] = a;
	}
	int x, y;
	cin >> x >> y;
	visited[x] = 1;

	while (x != p[x])
	{
		x = p[x];
		visited[x] = 1;
	}

	while (1)
	{
		if (visited[y] == 1)
		{
			return y;
		}
		y = p[y];
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		memset(visited, 0, sizeof(int) * n);

		cout << lca(n) << "\n";
	}

	return 0;
}