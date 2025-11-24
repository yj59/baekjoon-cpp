#include <iostream>
#include <string>
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

char board[21][21];
bool visited[26];
int r, c, ans = 0;

void solve(int x, int y, int len)
{
	ans = max(ans, len);

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;

		int ctoi = board[ny][nx] - 'A';
		if (visited[ctoi]) continue;

		visited[ctoi] = 1;
		solve(nx, ny, len + 1);
		visited[ctoi] = 0;
	}
}

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < c; j++)
		{
			board[i][j] = str[j];
		}
	}

	visited[board[0][0] - 'A'] = 1;
	solve(0, 0, 1);
	cout << ans;

	return 0;
}