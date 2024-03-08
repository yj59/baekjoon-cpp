#include <cstdio>

int main()
{
	// init & input
	int n, m;
	int list[100002];
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		int el;
		scanf("%d", &list[i]);
		list[i] += list[i - 1];
	}

	// prefix sum
	for (int i = 0; i < m; i++)
	{
		int st, e;
		scanf("%d %d", &st, &e);
		printf("%d\n", list[e] - list[st - 1]);
	}
}