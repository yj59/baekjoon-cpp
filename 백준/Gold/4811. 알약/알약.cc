#include <iostream>
#include <cstring>

long long dp[31][31];
long long rec(int w, int h)
{
	if (dp[w][h] != -1) return dp[w][h];
	if (!w) return 1;
	if (!h) return dp[w][h] = rec(w - 1, h + 1);
	return dp[w][h] = rec(w - 1, h + 1) + rec(w, h - 1);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	while (1)
	{
		// input & init
		int input;
		std::cin >> input;
		if (!input) break;

		rec(input, 0);
		std::cout << dp[input][0] << "\n";
	}

	return 0;
}
