#include <iostream>
#include <cstring>
using namespace std;

int map[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&map[0][0], &map[100][101], 1e9);

	// input & init
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		map[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if(map[a][b] > c) map[a][b] = c;
	}

	// floyde-warshall
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[i][k] + map[k][j] < map[i][j]) map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	// output
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 1e9) cout << "0 ";
			else cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}