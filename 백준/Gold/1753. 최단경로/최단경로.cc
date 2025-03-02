#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[20002];

vector<int> dijkstra(int n, int st)
{
	vector<int> dist(n + 1);
	fill(dist.begin(), dist.end(), 1e9);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, st });
	dist[st] = 0;

	while (!pq.empty())
	{
		int cur_cost = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (cur_cost > dist[cur_node]) continue;

		for (auto nei : graph[cur_node])
		{
			int next_node = nei.first;
			int next_cost = cur_cost + nei.second;

			if (next_cost > dist[next_node]) continue;

			dist[next_node] = next_cost;
			pq.push({ -next_cost, next_node });
		}
	}

	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int V, E, st;
	cin >> V >> E >> st;

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({ v, w });
	}

	vector<int> ans = dijkstra(V, st);

	for (int i = 1; i <= V; i++)
	{
		if (ans[i] == 1e9) cout << "INF\n";
		else cout << ans[i] << "\n";
	}
	return 0;
}