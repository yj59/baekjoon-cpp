#include <iostream>
#include <algorithm>
using namespace std;

int a[10001];
int dp[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input & init
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	fill(dp + 1, dp + k + 1, 1e9);

	// solve
	for (int i = 1; i <= n; i++)
	{
		for (int j = a[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
		}
	}

	// output
	if (dp[k] == 1e9) cout << -1;
	else cout << dp[k];

	return 0;
}