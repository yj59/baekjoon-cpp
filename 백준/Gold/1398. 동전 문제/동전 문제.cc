#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	int dp[101] = { 0 };
	scanf("%d", &t);

	for (int i = 1; i < 101; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i - 10 >= 0) dp[i] = min(dp[i], dp[i - 10] + 1);
		if (i - 25 >= 0) dp[i] = min(dp[i], dp[i - 25] + 1);
	}

	while (t--)
	{
		long long n, ret = 0;
		scanf("%lld", &n);

		while (n)
		{
			ret += dp[n % 100];
			n /= 100;
		}
		printf("%lld\n", ret);
	}

	return 0;
}