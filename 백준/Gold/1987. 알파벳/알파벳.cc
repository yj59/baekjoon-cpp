#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

vector<string> map;
int visited[26] = { 0, };
int r, c, result = 0;

void solve(int x, int y, int cur)
{
	result = max(result, cur);

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;

		char idx = map[ny][nx] - 'A';
		if (visited[idx]) continue;

		visited[idx] = 1;
		solve(nx, ny, cur + 1);
		visited[idx] = 0;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;

	map.resize(r);
	for (int i = 0; i < r; i++)
	{
		cin >> map[i];
	}

	visited[map[0][0] - 'A'] = 1;
	solve(0, 0, 1);

	cout << result;
	return 0;
}