#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// input & init
	long long int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		long long int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	long long int st = 1, e = v.back() * m;

	// binary search
	while (st <= e)
	{
		long long int mid = (st + e) / 2;
		long long int cnt = 0;

		for (int i = 0; i < v.size(); i++)
		{
			cnt += mid / v[i];
			if (cnt > m) break;
		}

		if (cnt >= m)
		{
			e = mid - 1;
		}
		else
		{
			st = mid + 1;
		}
	}

	// output
	cout << st;

	return 0;
}