#include <iostream>
#include <vector>
using namespace std;

int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int idx1 = 0, idx2 = 0;
	int sum = arr[0];
	int ans = n + 1;

	while (idx1 <= idx2 && idx2 < n)
	{
		if (sum < s)
		{
			idx2++;
			sum += arr[idx2];
		}
		else if (sum == s)
		{
			if (idx2 - idx1 + 1 < ans)
			{
				ans = idx2 - idx1 + 1;
			}
			idx2++;
			sum += arr[idx2];
		}
		else if (sum > s)
		{
			if (idx2 - idx1 + 1 < ans)
			{
				ans = idx2 - idx1 + 1;
			}
			sum -= arr[idx1];
			idx1++;
		}
	}
	if (ans > n)
	{
		ans = 0;
	}
	cout << ans;
	return 0;
}