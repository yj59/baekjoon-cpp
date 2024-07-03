#include <iostream>
using namespace std;

char map[10001][501];
bool visited[10001][501] = { 0, };
int dist[3][2] = { {-1, 1}, {0, 1}, {1, 1} };
int r, c;

bool dfs(int x, int y)
{
	if (y == c - 1) return 1;

	for (int* d : dist)
	{
		int nx = x + d[0];
		int ny = y + d[1];

		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (visited[nx][ny] || map[nx][ny] == 'x') continue;

		visited[nx][ny] = 1;
		if (dfs(nx, ny)) return 1;
	}

	return 0;
}

int main()
{
	// input & init
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%1s", &map[i][j]);
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < r; i++)
	{
		cnt += dfs(i, 0);
	}

	printf("%d", cnt);
	return 0;
}