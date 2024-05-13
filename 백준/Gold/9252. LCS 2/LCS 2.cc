#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int dp[1002][1002] = { 0, };

int main()
{
	string a, b;
	cin >> a >> b;

	int sa = a.size();
	int sb = b.size();

	a.insert(0, " ");
	b.insert(0, " ");
	
	// lcs 길이
	for (int i = 1; i <= sa; i++)
	{
		for (int j = 1; j <= sb; j++)
		{
			if (a[i] == b[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	// lcs 찾기
	cout << dp[sa][sb] << "\n";

	if(dp[sa][sb])
	{
		string lcs;
		int i = sa;
		int j = sb;

		while(dp[i][j])
		{
			if (dp[i][j] == dp[i - 1][j])
			{
				i--;
			}
			else if (dp[i][j] == dp[i][j - 1])
			{
				j--;
			}
			else
			{
				lcs += a[i];
				i--;
				j--;
			}
		}

		reverse(lcs.begin(), lcs.end());
		cout << lcs << endl;
	}

	return 0;
}