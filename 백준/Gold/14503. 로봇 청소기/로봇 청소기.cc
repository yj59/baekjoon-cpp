#include <iostream>
using namespace std;

int dx[] = { 0, 1, 0, -1 }; // 북 동 남 서
int dy[] = { -1, 0, 1, 0 };

int map[51][51];
int n, m;
int cnt = 0;

int turn(int d)
{
	return (d + 3) % 4;
}

void clean(int y, int x, int d)
{
	if (map[y][x] == 0)
	{
		map[y][x] = -1;
		cnt++;
	}

	int nd = d;
	for (int i = 0; i < 4; i++)
	{
		nd = turn(nd);
		int nx = x + dx[nd];
		int ny = y + dy[nd];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

		if (map[ny][nx] == 0)
		{
			clean(ny, nx, nd);
			return;
		}
	}

	int bx = x - dx[d];
	int by = y - dy[d];

	if (by < 0 || by >= n || bx < 0 || bx >= m) return;
	if (map[by][bx] == 1) return;

	clean(by, bx, d);
}

int main()
{
	
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	clean(r, c, d);

	cout << cnt;
	return 0;
}