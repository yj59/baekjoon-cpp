#include <iostream>
using namespace std;

int coins[100];
int dp[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// input & init
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}

	// dynamic programming
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = coins[i]; j <= k; j++)
		{
			dp[j] += dp[j - coins[i]];
		}
	}

	// output
	cout << dp[k];

	return 0;
}