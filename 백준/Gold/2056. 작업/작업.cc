#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int n, m, i, j, a, b, cw, ans = 0;
vector<int> AM[10001];
int Degree[10001] = { 0, };
int Work[10001];
int DP[10001];

int main()
{
	queue<int> q;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &Work[i]);
		scanf("%d", &m);

		for (j = 0; j < m; j++)
		{
			scanf("%d", &cw);
			AM[cw].push_back(i);
			Degree[i]++;
		}
	}

	for (i = 1; i <= n; i++)
	{
		if (Degree[i] == 0)
		{
			q.push(i);
			DP[i] = Work[i];
		}
	}

	while (!q.empty())
	{
		a = q.front(); q.pop();
		for (i = 0; i < AM[a].size(); i++)
		{
			b = AM[a][i];
			Degree[b]--;
			if (DP[b] < DP[a] + Work[b]) DP[b] = DP[a] + Work[b];
			if (Degree[b] == 0) q.push(b);
		}
	}

	for (i = 1; i <= n; i++)
		if (ans < DP[i]) ans = DP[i];
	
	printf("%d", ans);
	return 0;
}