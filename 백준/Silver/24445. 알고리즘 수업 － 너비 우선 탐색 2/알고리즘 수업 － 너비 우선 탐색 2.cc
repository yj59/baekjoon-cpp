#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int* visited;
vector<int>* isGraph;
queue<int> Queue;
int cnt{};
void BFS(int v, int e, int r);

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, r; // n:정점의 수, m:간선의 수, r:시작 정점
	cin >> n >> m >> r;

	visited = new int[n + 1]{ 0, };

	isGraph = new vector<int>[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		isGraph[a].emplace_back(b);
		isGraph[b].emplace_back(a);
	}
	for (int i = 0; i < n + 1; ++i)
	{
		if (isGraph[i].size() > 0)
			sort(isGraph[i].begin(), isGraph[i].end(), compare);
	}

	BFS(n, m, r);

	for (int i = 1; i < n + 1; ++i)
		cout << visited[i] << "\n";
}

void BFS(int v, int e, int r)
{
	visited[r] = ++cnt;
	Queue.push(r);
	while (!Queue.empty())
	{
		int u = Queue.front();
		Queue.pop();
		for (int j = 0; j < isGraph[u].size(); ++j)
		{
			int y = isGraph[u][j];
			if (visited[y] == 0)
			{
				Queue.push(y);
				visited[y] = ++cnt;
			}
		}
	}
}