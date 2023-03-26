#include <cstdio>
#include <vector>
#include <queue>
#define MAX 32002
using namespace std;
vector<int> AM[MAX];
int Degree[MAX] = { 0, };
int n, m, a, b;

int main()
{
	queue<int> q;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		AM[a].push_back(b);
		Degree[b]++;
	}

	for (int i = 1; i <= n; i++)
		if (Degree[i] == 0) q.push(i);

	while (!q.empty())
	{
		a = q.front();
		q.pop();

		printf("%d ", a);

		for (int i = 0; i < AM[a].size(); i++)
		{
			b = AM[a][i];
			Degree[b]--;
			if (Degree[b] == 0) q.push(b);
		}
	}
	return 0;
}