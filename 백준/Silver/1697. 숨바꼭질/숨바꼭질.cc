#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
queue<pair<int, int>> q;

void enqueue(int node, int time)
{
	if (node >= 100001 || node < 0 || visited[node]) return;

	visited[node] = true;
	q.push({ node, time });

	return;
}

int bfs(int n, int k)
{
	q.push({ n, 0 });

	while (!q.empty())
	{
		int x = q.front().first;
		int t = q.front().second;

		q.pop();

		if (x == k)
		{
			return t;
		}

		enqueue(x + 1, t + 1);
		enqueue(x - 1, t + 1);
		enqueue(2 * x, t + 1);
	}

	return -1;
}

int main()
{
	int n, k;
	cin >> n >> k;

	cout << bfs(n, k);
	return 0;
}