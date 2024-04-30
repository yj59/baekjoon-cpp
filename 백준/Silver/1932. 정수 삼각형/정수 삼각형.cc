#include <iostream>
using namespace std;

int dp[501][501];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> dp[i][j];
		}
	}

	int sum = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
			if (sum < dp[i][j]) sum = dp[i][j];
		}
	}

	cout << sum;
	return 0;
}