#include<iostream>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int map[504][504];
int dp[504][504];
int n;

int dynamicprogramming(int y, int x) 
{
	if (dp[y][x] != 0) return dp[y][x];

	dp[y][x] = 1;

	for (int dir = 0; dir < 4; dir++) 
	{ 
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

		if (map[ny][nx] > map[y][x]) 
		{ 
			dp[y][x] = max(dp[y][x], dynamicprogramming(ny, nx) + 1);
		}
	}
	return dp[y][x];
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> map[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			ans = max(ans, dynamicprogramming(i, j));
		}
	}

	cout << ans;
	return 0;
}