#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[1001];
bool dvisited[1001];
bool bvisited[1001];
int n, m, st;

void dfs(int num, int node)
{
	if (num == n) return;

	for (int i = 0; i < v[node].size(); i++)
	{
		int next = v[node][i];

		if (dvisited[next]) continue;

		dvisited[next] = 1;
		cout << next << " ";

		dfs(num + 1, next);
	}
}

void bfs()
{
	cout << "\n" << st << " ";
	bvisited[st] = 1;

	queue<int> q;
	q.push(st);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i];
			if (bvisited[next]) continue;

			bvisited[next] = 1;
			cout << next << " ";

			q.push(next);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// input & init
	cin >> n >> m >> st;
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	// dfs
	cout << st << " ";
	dvisited[st] = 1;
	dfs(1, st);

	// bfs
	bfs();

	return 0;
}