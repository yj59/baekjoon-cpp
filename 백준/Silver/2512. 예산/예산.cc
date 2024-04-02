#include <iostream>
#include <algorithm>
using namespace std;

int arr[10002];

int binarySearch(int total, int n)
{
	int e = arr[n - 1];
	int ans = 0;
	int st = 0;

	while (st <= e)
	{
		int sum = 0;
		int mid = (st + e) / 2;

		for (int i = 0; i < n; i++)
		{
			sum += min(arr[i], mid);
		}

		if (total >= sum)
		{
			ans = mid;
			st = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> m;

	sort(arr, arr + n);

	cout << binarySearch(m, n);

	return 0;
}