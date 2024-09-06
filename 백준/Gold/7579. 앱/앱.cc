#include <iostream>
#include <cmath>

using namespace std;

int dp[101][10001] = { 0, };
int app[101][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// init & input
	int N, M, m = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> app[i][0];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> app[i][1];
		m += app[i][1];
	}

	// dynamic programming 
	for (int i = 1; i <= N; i++)
	{
		int ci = app[i][0];
		int mi = app[i][1];

		for (int j = 0; j <= m; j++)
		{
			if (mi > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - mi] + ci);
		}
	}
	
	// output
	int minimum = 10001;

	for (int i = 0; i <= m; i++)
	{
		if (dp[N][i] >= M && minimum > i)
		{
			minimum = i;
		}
	}

	cout << minimum;
	return 0;
}