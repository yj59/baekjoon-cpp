#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
	int from, to, cost;
};

vector<Edge> edges;

bool bellmanFord(int n)
{
	vector<int> dist(n + 1, 1e9);
	dist[1] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int pos = 0; pos < edges.size(); pos++)
		{
			int from = edges[pos].from;
			int to = edges[pos].to;
			int cost = edges[pos].cost;

			if (dist[from] + cost < dist[to])
			{
				dist[to] = dist[from] + cost;
			}
		}
	}

	for (int pos = 0; pos < edges.size(); pos++)
	{
		int from = edges[pos].from;
		int to = edges[pos].to;
		int cost = edges[pos].cost;

		if (dist[to] > dist[from] + cost) return 1;
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// test
	int test_case;
	cin >> test_case;

	for (int tc = 0; tc < test_case; tc++)
	{
		// input & init
		edges.clear();

		int n, m, w;
		cin >> n >> m >> w;

		for (int i = 0; i < m; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;

			edges.push_back({ s, e, t });
			edges.push_back({ e, s, t });
		}

		for (int i = 0; i < w; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;

			edges.push_back({ s, e, -t });
		}

		// solve
		if (bellmanFord(n)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}