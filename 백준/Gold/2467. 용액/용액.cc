#include <iostream>
#include <vector>
using namespace std;

int arr[100000];

void solve(int n)
{
	int st = 0;
	int e = n - 1;

	int ans1 = 0;
	int ans2 = 0;
	int mi = 2000000000;

	while (st < e)
	{
		int cal = arr[st] + arr[e];

		if (abs(cal) < abs(mi))
		{
			mi = cal;
			ans1 = arr[st];
			ans2 = arr[e];
		}

		if (cal == 0) break;

		if (cal < 0) st++;
		else e--;
	}

	cout << ans1 << " " << ans2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	solve(n);

	return 0;
}