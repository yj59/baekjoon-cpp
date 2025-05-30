#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
vector<pair<int, int>> graph[50001];

int dijkstra(int n)
{
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>> pq;

	dist[1] = 0;
	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		int cur_cost = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (cur_cost > dist[cur_node]) continue;

		for (auto& nei : graph[cur_node])
		{
			int next_node = nei.first;
			int next_cost = nei.second + cur_cost;

			if (next_cost < dist[next_node])
			{
				dist[next_node] = next_cost;
				pq.push({ -next_cost, next_node });
			}
		}
	}

	return dist[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	int ans = dijkstra(n);

	cout << ans;
	return 0;
}