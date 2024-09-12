#include <iostream>
using namespace std;

bool arr[401][401] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][k] && arr[k][j]) arr[i][j] = 1;
			}
		}
	}

	int s;
	cin >> s;

	while (s--)
	{
		int i, j;
		cin >> i >> j;

		if (arr[i][j]) cout << "-1\n";
		else if (arr[j][i]) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}