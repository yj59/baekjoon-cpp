#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

string board[52];
int dist[52][52];
int cnt = 0;
int L, W;

void init()
{
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < W; j++)
		{
			dist[i][j] = -1;
		}
	}
}

void bfs(int sx, int sy) 
{
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	dist[sx][sy] = 0;

	while (!q.empty()) 
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) 
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= L || ny < 0 || ny >= W) continue;
			if (dist[nx][ny] != -1) continue;
			if (board[nx][ny] == 'W') continue;

			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			cnt = max(dist[nx][ny], cnt);
			q.push({ nx,ny });
		}
	}

	init();
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// init & input
	cin >> L >> W;
	for (int i = 0; i < L; i++)
	{
		cin >> board[i];
	}
	init();

	for (int i = 0; i < L; i++) 
	{
		for (int j = 0; j < W; j++) 
		{
			if (board[i][j] == 'L' && dist[i][j] == -1)
			{
				bfs(i, j);
			}
		}
	}
	cout << cnt;
}