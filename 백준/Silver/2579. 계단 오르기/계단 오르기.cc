#include <iostream>
#include <cmath>
using namespace std;

int dp[301][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i][0];
	}

	dp[1][1] = dp[1][0];
	dp[2][1] = dp[1][0] + dp[2][0];
	dp[3][1] = max(dp[1][0], dp[2][0]) + dp[3][0];

	for (int i = 4; i <= n; i++)
	{
		dp[i][1] = max(dp[i - 1][0] + dp[i - 3][1], dp[i - 2][1]) + dp[i][0];
	}

	cout << dp[n][1];
	return 0;
}