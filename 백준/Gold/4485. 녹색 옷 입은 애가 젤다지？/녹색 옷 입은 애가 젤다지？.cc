#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int map[125][125];
int dist[125][125];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int solve(int n)
{
	fill(dist[0], &dist[n - 1][n], 1e9);

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

	pq.push({ map[0][0], 0, 0 });
	dist[0][0] = map[0][0];

	while (!pq.empty())
	{
		int cost, x, y;
		tie(cost, x, y) = pq.top();
		pq.pop();

		if (cost > dist[x][y]) continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			int ncost = cost + map[nx][ny];

			if (ncost >= dist[nx][ny]) continue;

			dist[nx][ny] = ncost;
			pq.push({ ncost, nx, ny });
		}
	}

	return dist[n - 1][n - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc = 1;
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}

		cout << "Problem " << tc++ << ": " << solve(n) << "\n";
	}

	return 0;
}