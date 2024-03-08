#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// init & input
	int n, h;
	int odd[100000];
	int even[100000];

	cin >> n >> h;
	for (int i = 0; i < n / 2; i++)
	{
		cin >> odd[i] >> even[i];
	}

	sort(odd, odd + (n / 2));
	sort(even, even + (n / 2));

	// prefix sum
	int min = 200000;
	int sec = 0;
	for (int i = 1; i <= h; i++)
	{
		int cnt = lower_bound(odd, odd + (n / 2), i) - odd;
		cnt += upper_bound(even, even + (n / 2), h - i) - even;
		cnt = n - cnt;

		if (min == cnt)
		{
			sec++;
		}
		else if (min > cnt)
		{
			min = cnt;
			sec = 1;
		}
	}

	cout << min << " " << sec;
	return 0;
}