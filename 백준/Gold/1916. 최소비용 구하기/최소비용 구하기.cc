#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[1001];
int cost[1001];

void dijkstra(int st)
{
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, st });
	cost[st] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist > cost[now]) continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int ndist = graph[now][i].second;
			int next = graph[now][i].first;

			int cal = ndist + dist;
			if (cal < cost[next])
			{
				cost[next] = cal;
				pq.push({ -cal, next });
			}
		}
	}
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
	}
	fill(cost, cost + n + 1, 1e9);

	int st, e;
	cin >> st >> e;

	dijkstra(st);
	cout << cost[e];

	return 0;
}