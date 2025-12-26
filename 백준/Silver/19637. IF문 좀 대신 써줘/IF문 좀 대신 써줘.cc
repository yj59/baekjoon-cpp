#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int m, vector<pair<int, string>> v)
{
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;

		int l = 0;
		int r = n - 1;
		int ans = r;

		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (v[mid].first >= tmp)
			{
				r = mid - 1;
				ans = mid;
			}
			else
			{
				l = mid + 1;
			}
		}

		cout << v[ans].second << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<pair<int, string>> v(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].second >> v[i].first;
	}

	solve(n, m, v);
	return 0;
}