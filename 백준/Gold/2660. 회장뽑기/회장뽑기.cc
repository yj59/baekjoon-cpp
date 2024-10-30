#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input & init
	int fw[51][51];
	int ans[51];
	int n;
	cin >> n;

	fill(&fw[0][0], &fw[n][n + 1], 1e9);

	while (1)
	{
		int a, b;
		cin >> a >> b;

		if (a == -1) break;

		fw[a][b] = 1;
		fw[b][a] = 1;
	}

	// floyd-warshall
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				fw[i][j] = min(fw[i][k] + fw[k][j], fw[i][j]);
			}
		}
	}

	int res = 1e9;
	int idx = 0;
	for (int i = 1; i <= n; i++)
	{
		int score = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			score = max(score, fw[i][j]);
		}

		if (score > res) continue;
		else if (score < res)
		{
			res = score;
			idx = 0;
		}
		ans[idx++] = i;
	}

	// output
	cout << res << " " << idx << "\n";
	for (int i = 0; i < idx; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}