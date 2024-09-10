#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int dist[1001];
int route[1001];
vector<int> ans;

void dijkstra(int st, vector<pair<int, int>>graph[])
{
	fill(dist, dist + 1001, 1e9);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, st });
	dist[st] = 0;

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
				route[next] = cur;
				
				pq.push(make_pair(-calc, next));
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
	int idx = e;
	while (idx)
	{
		ans.push_back(idx);
		idx = route[idx];
	}
	cout << dist[e] << "\n" << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i] << " ";
	}

	return 0;
}