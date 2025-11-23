#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

bool map[101][101];
bool visited[101][101];
int dist[101][101];

int bfs(int n, int m)
{
	int step = 0;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	dist[0][0] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == m - 1 && y == n - 1) return dist[y][x];

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (visited[ny][nx] || !map[ny][nx]) continue;

			q.push({ nx, ny });
			visited[ny][nx] = 1;
			dist[ny][nx] = dist[y][x] + 1;
		}
	}

	return -1;
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = int(str[j]) - '0';
		}
	}

	cout << bfs(n, m);
	return 0;
}