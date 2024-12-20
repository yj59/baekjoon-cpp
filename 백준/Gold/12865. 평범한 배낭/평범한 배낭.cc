#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input & init
	int n, k;
	cin >> n >> k;

	int* dp = new int[k + 1];
	memset(dp, 0, k * sizeof(int));

	// solve
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;

		for (int j = k; j >= w; j--)
		{
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}

	// output
	cout << dp[k];

	return 0;
}