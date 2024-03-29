#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n, m;
int seq[8];

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < cnt; i++)
		{
			printf("%d ", seq[i]);
		}
		printf("\n");
		return;
	}

	int dupe = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dupe != i);
		{
			seq[cnt] = i;
			dupe = seq[cnt];
			dfs(cnt + 1);
		}
	}
}

int main()
{
	// init & input
	scanf("%d %d", &n, &m);

	dfs(0);
}