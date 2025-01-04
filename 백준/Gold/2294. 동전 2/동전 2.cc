#include <iostream>
#include <cmath>
using namespace std;
int dp[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// input & init
	int n, k;
	cin >> n >> k;
	fill(dp + 1, dp + k + 1, 1e9);

	// dynamic programming
	for (int i = 0; i < n; i++)
	{
		int coin;
		cin >> coin;

		for (int j = coin; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - coin] + 1);
		}
	}
	
	// output
	if (dp[k] == 1e9) cout << -1;
	else cout << dp[k];

	return 0;
}