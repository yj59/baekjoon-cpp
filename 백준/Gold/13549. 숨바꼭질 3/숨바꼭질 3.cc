#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[100001];

int solve(int n, int k)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, n });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int x = pq.top().second;
		pq.pop();
		visited[x] = true;

		if (x == k) return cost;

		if (x * 2 < 100001 && !visited[x * 2])
		{
			pq.push({ -cost, x * 2 });
		}
		if (x + 1 < 100001 && !visited[x + 1])
		{
			pq.push({ -(cost + 1) , x + 1 });
		}
		if (x - 1 >= 0 && !visited[x - 1])
		{
			pq.push({ -(cost + 1), x - 1 });
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	cout << solve(n, k);
	return 0;
}