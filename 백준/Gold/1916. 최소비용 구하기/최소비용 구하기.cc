#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1e9

vector<pair<int, int>> graph[1001];
int dist[1001];

void dijkstra(int start)
{
	// 거리, 노드
	priority_queue<pair<int, int>> pq;
	
	pq.push({ 0, start });	// 첫번째 노드비용 초기화
	dist[start] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;	// 현재 노드까지의 비용(오름차순 정렬을 위해 음수 붙임)
		int cur = pq.top().second;	// 현재 노드
		pq.pop();

		if (dist[cur] < cost) continue;
		
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int calc = cost + graph[cur][i].second;

			// 현재 계산값 더 작다면 최소비용 갱신
			if (calc < dist[graph[cur][i].first])
			{
				dist[graph[cur][i].first] = calc;
				pq.push(make_pair(-calc, graph[cur][i].first));
			}
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int st, e, cost;
		cin >> st >> e >> cost;
		graph[st].push_back({ e, cost });
	}

	int st, e;
	cin >> st >> e;

	fill(dist, dist + 1001, INF);

	dijkstra(st);

	cout << dist[e] << "\n";
	return 0;
}