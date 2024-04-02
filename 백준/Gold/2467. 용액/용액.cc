#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int l = 0;
	int r = n - 1;

	int min = 2000000001;
	int ml = 0;
	int mr = 0;

	while (l < r)
	{
		int sum = arr[l] + arr[r];

		if (abs(sum) < min)
		{
			min = abs(sum);
			ml = arr[l];
			mr = arr[r];

			if (min == 0) break;
		}
		if (sum < 0)
		{
			l++;
		}
		else
		{
			r--;
		}
	}

	cout << ml << " " << mr;
	return 0;
}