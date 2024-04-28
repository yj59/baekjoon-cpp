#include <iostream>
using namespace std;

int num[100001];
long long dp[1000001];

void sumOfDiv(int max)
{
	for (int i = 1; i <= max; i++)
	{
		for (int j = 1; j * i <= max; j++)
		{
			dp[i * j] += i;
		}
		dp[i] += dp[i - 1];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	// input & init
	int t, max = -1;
	cin >> t;
	for (int i = 1; i <= t; i++) 
	{
		cin >> num[i];
		if (num[i] > max) max = num[i];
	}

	// dynamic programming
	sumOfDiv(max);

	// output
	for (int i = 1; i <= t; i++)
	{
		cout << dp[num[i]] << "\n";
	}

	return 0;
}