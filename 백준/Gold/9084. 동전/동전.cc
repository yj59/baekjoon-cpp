#include <iostream>
#include <cstring>
using namespace std;

int dp[10001];
int coins[20];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		// input & init
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> coins[i];
		}

		int m;
		cin >> m;

		memset(dp, 0, (m + 1) * sizeof(int));
		dp[0] = 1;

		// dynamic programming
		for (int i = 0; i < n; i++)
		{
			for (int j = coins[i]; j <= m; j++)
			{
				dp[j] += dp[j - coins[i]];
			}
		}

		// output
		cout << dp[m] << "\n";
	}
	return 0;
}