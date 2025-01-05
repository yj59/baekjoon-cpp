#include <iostream>
using namespace std;
int dp[1500051];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	// input & init
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int t, p;
		cin >> t >> p;

		// dynamic programming
		dp[i + t] = max(dp[i + t], dp[i] + p);
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	// ouptut
	cout << dp[n + 1];
	return 0;
}