#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[801];
int cost[801];

int dijkstra(int st, int target)
{
	// init
	fill(cost, cost + 801, 1e9);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, st });
	cost[st] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (cost[now] < dist) continue;

		// implement
		for (int i = 0; i < graph[now].size(); i++)
		{
			int cal = dist + graph[now][i].second;
			int next = graph[now][i].first;

			if (cal < cost[next])
			{
				cost[next] = cal;
				pq.push({ -cal, next });
			}
		}
	}

	if (cost[target] == 1e9)
	{
		return -2e9;
	}
	return cost[target];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input & init
	int n, e;

	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });

	}

	int v1, v2;
	cin >> v1 >> v2;

	//dijkstra
	int common = dijkstra(v1, v2);
	int route1 = dijkstra(1, v1) + dijkstra(v2, n)  + common;
	int route2 = dijkstra(1, v2) + dijkstra(v1, n) + common;
	
	// output
	if ((route1 < 0 && route2 < 0))
	{
		cout << "-1";
	}
	else if (route1 > route2)
	{
		cout << route2;
	}
	else
	{
		cout << route1;
	}
	
	return 0;
}