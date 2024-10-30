#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fw[51][51];
vector<int> v;

int floydWarshall(int n)
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				fw[i][j] = min(fw[i][k] + fw[k][j], fw[i][j]);
			}
		}
	}

	int res = 1e9;
	for (int i = 1; i <= n; i++)
	{
		int score = 0;
		for (int j = 1; j <= n; j++)
		{
			score = max(score, fw[i][j]);
		}

		if (score > res) continue;
		else if (score < res)
		{
			res = score;
			v.clear();
		}
		v.push_back(i);
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input & init
	int n;
	cin >> n;

	fill(&fw[0][0], &fw[n][n + 1], 1e9);
	for (int i = 0; i <= n; i++)
	{
		fw[i][i] = 0;
	}

	while(1)
	{
		int a, b;
		cin >> a >> b;

		if (a == -1 && b == -1) break;

		fw[a][b] = 1;
		fw[b][a] = 1;
	}

	// solve
	cout << floydWarshall(n) << " " << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}