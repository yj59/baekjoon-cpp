#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[] = { 0, 1, 0, -1, 0, 0 };
int dy[] = { -1, 0, 1, 0, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

int box[101][101][101];
queue<tuple<int, int, int>> q;
int n, m, h;

void input()
{
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) q.push({ i, j, k });
			}
		}
	}
}

void solve()
{
	while (!q.empty())
	{
		int z = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h || box[nz][ny][nx] != 0) continue;
			box[nz][ny][nx] = box[z][y][x] + 1;
			q.push({ nz, ny, nx });
		}
	}
	
}

void output()
{
	int cnt = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (box[i][j][k] == 0)
				{
					cout << -1;
					return;
				}
				cnt = max(cnt, box[i][j][k]);
			}
		}
	}

	cout << cnt - 1;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();
	output();
	
	return 0;
}