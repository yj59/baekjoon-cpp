#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int fw[101][101];
int kb[101] = { 0, };

int floydWarshall(int n)
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			kb[i] += fw[i][j];
		}
		kb[i] -= fw[i][i];
	}

	int ans, min = 1e9;
	for (int i = 1; i <= n; i++)
	{
		if (kb[i] < min)
		{
			min = kb[i];
			ans = i;
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// input & init
	int n, m;
	cin >> n >> m;

	fill(&fw[0][0], &fw[n][n+1], 1e9);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		fw[a][b] = 1;
		fw[b][a] = 1;
	}

	// solve
	cout << floydWarshall(n);

	return 0;
}