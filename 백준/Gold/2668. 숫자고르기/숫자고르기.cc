#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int arr[101];
bool visited[101];
vector<int> ans;

void solve(int cur, int st)
{
	if (visited[cur])
	{
		if (st == cur)
		{
			ans.push_back(cur);
		}
		return;
	}

	visited[cur] = true;
	solve(arr[cur], st);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		solve(i, i);
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}