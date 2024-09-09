#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dijkstra(int start, int dist[], vector<pair<int, int>>graph[])
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost > dist[cur]) continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int calc = cost + graph[cur][i].second;
			int next = graph[cur][i].first;
			if (calc < dist[next])
			{
				dist[next] = calc;
				pq.push(make_pair(-calc, next));
			}
		}
	}
	return;
}

int meeting(int n, int k, vector<pair<int, int>>graph[])
{
	int sum[101] = { 0, };
	int dist[101];

	for (int i = 0; i < k; i++)
	{
		fill(dist, dist + 101, 1e9);

		int st;
		cin >> st;
		dijkstra(st, dist, graph);

		for (int j = 1; j <= n; j++)
		{
			sum[j] += dist[j];
		}
	}

	int ans = 0, min = 1e9;

	for (int i = 1; i <= n; i++)
	{
		if (min > sum[i])
		{
			ans = i;
			min = sum[i];
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		vector<pair<int, int>>graph[101];

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			graph[u].push_back({ v, w });
			graph[v].push_back({ u, w });
		}

		int k;
		cin >> k;

		cout << meeting(n, k, graph) << "\n";
	}

	return 0;
}