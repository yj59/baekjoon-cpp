#include <iostream>
#include <queue>
using namespace std;

int solve()
{
	int n, m;
	cin >> n >> m;

	queue<pair<int, int>> q;
	priority_queue<int> pq;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		q.push(make_pair(temp, i));
		pq.push(temp);
	}

	int cnt = 0;
	while (!q.empty())
	{
		int el = q.front().first;
		int idx = q.front().second;
		q.pop();

		if (pq.top() == el)
		{
			pq.pop();
			cnt++;
			if (idx == m) return cnt;
		}
		else
		{
			q.push(make_pair(el, idx));
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		cout << solve() << "\n";
	}
	return 0;
}