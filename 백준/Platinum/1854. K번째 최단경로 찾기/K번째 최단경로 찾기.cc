#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[1001];
priority_queue<int> dist[1001];

void dijkstra(int k)
{
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, 1 });
	dist[1].push(0);

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int calc = cost + graph[cur][i].second;
			int next = graph[cur][i].first;

			if (dist[next].size() >= k && calc >= dist[next].top()) continue;

			if (dist[next].size() == k)
			{
				dist[next].pop();
			}
			dist[next].push(calc);
			pq.push(make_pair(-calc, next));
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	dijkstra(k);

	for (int i = 1; i <= n; i++)
	{
		if (dist[i].size() != k) cout << "-1\n";
		else
		{
			cout << dist[i].top() << "\n";
		}
	}

	return 0;
}