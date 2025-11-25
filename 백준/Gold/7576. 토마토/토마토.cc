#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int box[1001][1001];
queue<pair<int, int>> q;

void bfs(int n, int m)
{
	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (box[ny][nx] != 0) continue;

			box[ny][nx] = box[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main()
{
	int m, n;
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
			{
				q.push({ i, j });
			}
		}
	}

	bfs(n, m);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

			cnt = max(cnt, box[i][j]);
		}
	}

	cout << cnt - 1;
	return 0;
}