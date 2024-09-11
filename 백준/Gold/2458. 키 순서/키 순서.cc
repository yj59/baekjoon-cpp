#include <iostream>
#include <cstring>
using namespace std;

bool dp[501][501] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b;

		dp[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dp[i][k] && dp[k][j]) dp[i][j] = 1;
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] || dp[j][i]) cnt++;
		}
		if (cnt == n - 1) ans++;
	}

	cout << ans << "\n";
	return 0;
}