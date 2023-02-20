#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int n, m, i, j, k, x, y, nx, ny, cnt, result = 0;
int map[10][10];
int sim[10][10];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
queue<pair<int, int>>q;

void bfs()
{
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			sim[i][j] = map[i][j];
			if (sim[i][j] == 2)	q.push(make_pair(i, j));
		}
	}

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (sim[nx][ny] == 0)
			{
				q.push(make_pair(nx, ny));
				sim[nx][ny] = 2;
			}
		}
	}
	cnt = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (sim[i][j] == 0) cnt++;

	if (cnt > result) result = cnt;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for (int x1 = 0; x1 < n; x1++)
	{
		for (int y1 = 0; y1 < m; y1++)
		{
			if (map[x1][y1] != 0) continue;

			for (int x2 = 0; x2 < n; x2++)
			{
				for (int y2 = 0; y2 < m; y2++)
				{
					if (map[x2][y2] != 0) continue;

					for (int x3 = 0; x3 < n; x3++)
					{
						for (int y3 = 0; y3 < m; y3++)
						{
							if (map[x3][y3] != 0) continue;

							if (x1 == x2 && y1 == y2) continue;
							if (x2 == x3 && y2 == y3) continue;
							if (x3 == x1 && y3 == y1) continue;

							map[x1][y1] = 1;
							map[x2][y2] = 1;
							map[x3][y3] = 1;
							bfs();

							map[x1][y1] = 0;
							map[x2][y2] = 0;
							map[x3][y3] = 0;
						}
					}
				}
			}
		}
	}
	printf("%d", result);
}