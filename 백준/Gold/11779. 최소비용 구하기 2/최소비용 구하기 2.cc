#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int dist[1001];
vector<int> route[1001];

void dijkstra(int st, vector<pair<int, int>>graph[])
{
	fill(dist, dist + 1001, 1e9);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, st });
	dist[st] = 0;
	route[st].push_back(st);

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
		if (cost > dist[cur]) continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int calc = cost + graph[cur][i].second;

			if (dist[next] > calc)
			{	
				dist[next] = calc;
				pq.push(make_pair(-calc, next));

				route[next].clear();
				for (int i = 0; i < route[cur].size(); i++)
				{
					route[next].push_back(route[cur][i]);
				}
				route[next].push_back(next);
			}
		}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// input & init
	vector<pair<int, int>> graph[1001];

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	int st, e;
	cin >> st >> e;
	
	// code
	dijkstra(st, graph);

	// output
	cout << dist[e] << "\n" << route[e].size() << "\n";
	for (int i = 0; i < route[e].size(); i++)
	{
		cout << route[e][i] << " ";
	}

	return 0;
}