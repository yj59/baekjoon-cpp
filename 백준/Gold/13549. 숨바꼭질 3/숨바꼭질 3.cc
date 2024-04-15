#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[100001];
int dp[100001];
int dx[2] = { -1, 1 };

int dijkstra(int st, int target)
{
	int next, ntime;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, st));
	dp[st] = 0;

	while (!pq.empty())
	{
		int time = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dp[now] < time) continue;

		for (int i = 0; i < 3; i++)
		{
			if (i == 2)
			{
				next = 2 * now;
				ntime = time;
			}
			else
			{
				next = now + dx[i];
				ntime = time + 1;
			}

			if (next < 0 || next > 100000) continue;

			if (dp[next] == -1 || dp[next] > ntime)
			{
				dp[next] = ntime;
				pq.push(make_pair(-ntime, next));
			}
		}
	}

	return dp[target];
}

int main()
{
	// input & init
	int n, k;
	cin >> n >> k;

	fill(dp, dp + 100001, -1);

	// dijkstra
	cout << dijkstra(n, k);
	return 0;
}