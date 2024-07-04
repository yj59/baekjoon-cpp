#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector<pair<int, int>> v;

long long bitmask(int n)
{
	long long ans = LLONG_MAX;
	for (int i = 1; i < (1 << n); i++)
	{
		long long mul = 1;
		long long sum = 0;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				mul *= v[j].first;
				sum += v[j].second;
			}
		}

		ans = min(ans, abs(sum - mul));
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// init & input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int f, s;
		cin >> f >> s;
		v.push_back({ f, s });
	}

	cout << bitmask(n);
	return 0;
}