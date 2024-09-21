#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int map[101][101];
int dist[101][101];
bool visited[101][101];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int dijkstra(int n)
{
	// init
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, 0 });
	visited[0][0] = 1;

	while (!pq.empty())
	{
		int x = pq.top().first;
		int y = pq.top().second;
		pq.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			int calc = dist[x][y] + map[nx][ny];
			if (!visited[nx][ny] || calc < dist[nx][ny])
			{
				dist[nx][ny] = calc;
				visited[nx][ny] = 1;
				pq.push(make_pair(nx, ny));
			}
		}
	}

	return dist[n - 1][n - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		// input & init
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		memset(dist, 0, sizeof(dist));

		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < n; j++)
			{
				map[i][j] = s[j] - '0';
			}
		}

		// solve
		cout << "#" << tc << " " << dijkstra(n) << "\n";
	}

	return 0;
}
