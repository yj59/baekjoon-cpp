#include <iostream>
#include <algorithm>

int main()
{
	int n, k;
	int v[101];

	scanf("%d %d", &n, &k);
	int* dp = new int[k + 1];

	for (int i = 1; i <= k; i++) dp[i] = 100001;
	dp[0] = 0;

	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	std::sort(v, v + n);

	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if ((v[j] <= i) && (dp[i - v[j]] < dp[i])) dp[i] = dp[i - v[j]] + 1;
		}
	}

	if (dp[k] == 100001) printf("-1");
	else printf("%d", dp[k]);
	return 0;
}