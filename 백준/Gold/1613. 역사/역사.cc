#include <iostream>
using namespace std;

bool arr[401][401] = { 0, };

void Input(int n)
{
	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	return;
}

void floydwarshall(int n)
{
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
	return;
}

void output()
{
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
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	Input(n);
	floydwarshall(n);
	output();

	return 0;
}