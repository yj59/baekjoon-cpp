#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

char map[101][101];
bool visited[101][101];

void init(int n)
{
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 'G') map[i][j] = 'R';
		}
	}
}

int	bfs(int n)
{
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j]) continue;

			visited[i][j] = 1;
			queue<pair<int, int>> q;
			q.push({ i, j });

			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx < 0 || ny < 0 || nx >= n || ny >= n || map[x][y] != map[nx][ny] || visited[nx][ny]) continue;

					visited[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
			cnt++;
		}
	}
	
	return cnt;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1s", &map[i][j]);
		}
	}

	printf("%d ", bfs(n));
	init(n);
	printf("%d", bfs(n));

	return 0;
}