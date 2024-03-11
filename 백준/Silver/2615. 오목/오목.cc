#include <cstdio>

int dt[4][2] = { {-1, 1}, {0, 1}, {1, 1}, {1, 0} };
int board[20][20];
int visited[20][20][4] = { 0, };

int cnt = 0;
int resX, resY;

void dfs(int x, int y, int dir)
{
	visited[x][y][dir] = 1;
	cnt++;

	int nx = x + dt[dir][0];
	int ny = y + dt[dir][1];

	if (board[x][y] == board[nx][ny])
	{
		dfs(nx, ny, dir);
	}

	return;
}

bool bruteforce()
{
	bool fin = false;

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (!board[j][i]) continue;
			
			for (int k = 0; k < 4; k++)
			{
				if (visited[j][i][k]) continue;

				dfs(j, i, k);

				if (cnt == 5)
				{
					fin = true;
					resX = j;
					resY = i;
				}
				cnt = 0;
			}
		}
	}
	return fin;
}

int main()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	if (bruteforce())
	{
		printf("%d\n%d %d", board[resX][resY], resX + 1, resY + 1);
	}
	else
	{
		printf("0\n");
	}

	return 0;
}