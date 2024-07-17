#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int map[1000][1000];
int dist[1000][1000][2];
int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	queue<tuple<int, int, int>> q;
	dist[0][0][0] = 1;
	q.push(make_tuple(0, 0, 0));

	while (!q.empty())
	{
		int x, y, flag;
		tie(x, y, flag) = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			// 장애물이 없을 경우 && 벽을 부수지 않았을 경우
			if (map[nx][ny] == 0 && dist[nx][ny][flag] == 0)
			{
				dist[nx][ny][flag] = dist[x][y][flag] + 1;
				q.push(make_tuple(nx, ny, flag));
			}

			if (flag == 0 && map[nx][ny] == 1 && dist[nx][ny][flag + 1] == 0)
			{
				dist[nx][ny][flag + 1] = dist[x][y][flag] + 1;
				q.push(make_tuple(nx, ny, flag + 1));
			}
		}
	}

	if (dist[n - 1][m - 1][0] != 0 && dist[n - 1][m - 1][1] != 0)
	{
		std::cout << min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
	}
	else if (dist[n - 1][m - 1][0] != 0)
	{
		std::cout << dist[n - 1][m - 1][0];
	}
	else if (dist[n - 1][m - 1][1] != 0)
	{
		std::cout << dist[n - 1][m - 1][1];
	}
	else std::cout << -1;

	std::cout << "\n";

	return 0;
}