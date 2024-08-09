#include <iostream>
#include <vector>
using namespace std;

vector<long long>dp;

int main()
{
	int n;
	cin >> n;

	dp.push_back(1);
	dp.push_back(2);

	if (n > 2)
	{
		for (int i = 2; i < n; i++)
		{
			long long tmp = (dp[i - 1] + dp[i - 2]) % 15746;
			dp.push_back(tmp);
		}
	}
	
	cout << dp[n-1];
}