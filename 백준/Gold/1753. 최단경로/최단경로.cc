#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[20001];
int cost[20001];


void dijkstra(int st)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, st });
	cost[st] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist > cost[node]) continue;

		for (int i = 0; i < graph[node].size(); i++)
		{
			int next = graph[node][i].first;
			int ndist = graph[node][i].second;

			int cal = dist + ndist;

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
	int v, e, st;
	cin >> v >> e >> st;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });	
	}

	fill(cost, cost + v + 1, 1e9);

	dijkstra(st);

	for (int i = 1; i <= v; i++)
	{
		if (cost[i] == 1e9) cout << "INF\n";
		else cout << cost[i] << "\n";
	}

	return 0;
}