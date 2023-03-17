#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, a, b, x, i;
vector<int> v[50001];
int d[50001] = { 0, };
int p[50001] = { 0, };
bool ch[50001];

int main()
{
	queue<int> q;
	scanf("%d", &n);
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	ch[1] = true;
	q.push(1);
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		for (int y : v[x])
		{
			if (!ch[y])
			{
				d[y] = d[x] + 1;
				ch[y] = true;
				p[y] = x;
				q.push(y);
			}
		}
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		if (d[a] < d[b]) swap(a, b);
		while (d[a] != d[b]) a = p[a];
		while (a != b)
		{
			a = p[a];
			b = p[b];
		}
		printf("%d\n", a);
	}
	return 0;
}