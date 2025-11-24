#include <iostream>
using namespace std;

int ability[21][21];
bool visited[21];
int n, ans = 1e9;

void solve(int cnt, int num)
{
	if (cnt == n / 2)
	{
		int link = 0, start = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i] && visited[j]) link += ability[i][j];
				else if (!visited[i] && !visited[j]) start += ability[i][j];
			}
		}

		int sub = abs(link - start);
		if (sub < ans) ans = sub;
		return;
	}

	for (int i = num; i < n; i++)
	{
		visited[i] = true;
		solve(cnt + 1, i + 1);
		visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> ability[i][j];
		}
	}

	solve(0, 0);
	cout << ans;

	return 0;
}