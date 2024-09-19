#include <iostream>
#include <set>
using namespace std;

int solve(int n)
{
	bool check[1001] = { 0, };

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n - i; j++)
		{
			for (int k = 0; k <= n - i - j; k++)
			{
				int l = n - i - j - k;
				int calc = i + j * 5 + k * 10 + l * 50;
				check[calc] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 1001; i++)
	{
		if (check[i]) ans++;
	}
	return ans;
}

int main()
{
	// input
	int n;
	cin >> n;

	// output
	cout << solve(n);
	return 0;
}