#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

bool map[51][51];
bool visited[51][51];

void init()
{
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
}

void bfs(int x, int y, int m, int n)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = 1;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (visited[ny][nx] || !map[ny][nx]) continue;

			visited[ny][nx] = 1;
			q.push({ nx, ny });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		init();

		int m, n, k; // m: 가로, n: 세로
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visited[i][j] && map[i][j])
				{
					bfs(j, i, m, n);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}