#include <iostream>
using namespace std;
bool num[1001];

int solve(int n, int k)
{
	int cnt = 0;
	for (int i = 2; i < n + 1; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			if (num[j]) continue;

			num[j] = 1;
			cnt++;
			if (k == cnt)
			{
				return j;
			}
		}
	}
	return -1;
}

int main()
{
	int n, k;
	cin >> n >> k;

	cout << solve(n, k);
	return 0;
}