#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int n, r1, c1, r2, c2, x, y, nx, ny, i;
int dx[] = { -2, -2, 0, 0, 2, 2 };
int dy[] = { -1, 1, -2, 2, -1, 1 };
int dist[200][200] = { 0, };
queue<pair<int, int>> q;

int main()
{
	scanf("%d %d %d %d %d", &n, &r1, &c1, &r2, &c2);
	q.push(make_pair(r1, c1));

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (i = 0; i < 6; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] == 0)
			{
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	if (dist[r2][c2] == 0) printf("-1");
	else printf("%d", dist[r2][c2]);
}