#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

vector<pair<int, int>> graph[20001];
int sumOfTheCosts[20001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	sumOfTheCosts[start] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (cost > sumOfTheCosts[node]) continue;

		for (int i = 0; i < graph[node].size(); i++)
		{
			int calc = cost + graph[node][i].second;

			if (calc < sumOfTheCosts[graph[node][i].first])
			{
				sumOfTheCosts[graph[node][i].first] = calc;
				pq.push(make_pair(-calc, graph[node][i].first));
			}
		}
	}
	return;
}

int main()
{
	int vertex, edge, st;
	cin >> vertex >> edge >> st;

	for (int i = 0; i < edge; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	fill(sumOfTheCosts, sumOfTheCosts + 20001, INF);

	dijkstra(st);

	for (int i = 1; i <= vertex; i++)
	{
		if (sumOfTheCosts[i] < INF) cout << sumOfTheCosts[i] << "\n";
		else cout << "INF\n";
	}

	return 0;
}