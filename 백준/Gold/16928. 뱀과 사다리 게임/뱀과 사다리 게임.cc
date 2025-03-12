#include <iostream>
#include <queue>
using namespace std;

int board[101] = { 0, };
bool visited[101] = {0, };

int bfs()
{
	queue<pair<int, int>> q;
	q.push({ 1, 0 });

	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int nx = x + i;

			if (visited[nx]) continue;
			if (nx >= 100)
			{
				return cnt + 1;
			}

			if (board[nx] != 0)
			{
				nx = board[nx];
			}

			q.push(make_pair(nx, cnt + 1));
			visited[nx] = 1;
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x] = y;
	}

	// solve
	cout << bfs();

	return 0;
}