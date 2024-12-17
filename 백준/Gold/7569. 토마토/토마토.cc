#include <iostream>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;

int dx[6] = { -1, 0, 1, 0, 0, 0 };
int dy[6] = { 0, -1, 0, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

int box[101][101][101];
int visited[101][101][101];
queue<tuple<int, int, int>> q;

int solve(int n, int m, int h)
{
	// bfs
	while (!q.empty())
	{
		tuple<int, int, int> t = q.front();
		int z = get<0>(t);
		int y = get<1>(t);
		int x = get<2>(t);
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (box[nz][ny][nx] == 0)
			{
				box[nz][ny][nx] = box[z][y][x] + 1;
				q.push({ nz, ny, nx });
			}
		}
	}

	// calc
	int day = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (box[i][j][k] == 0)
				{
					return -1;
				}

				day = max(day, box[i][j][k]);
			}
		}
	}

	return day - 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input
	int n, m, h;
	cin >> n >> m >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
				{
					q.push({ i, j, k });
				}
			}
		}
	}

	// output
	cout << solve(n, m, h);

	return 0;
}
