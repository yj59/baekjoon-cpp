#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int parent[1000001];

int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	int px = Find(x);
	int py = Find(y);

	if (px == py) return;
	if (px < py) parent[py] = px;
	else parent[px] = py;
}

bool CheckUnion(int x, int y)
{
	int px = Find(x);
	int py = Find(y);

	if (px == py) return 1;
	return 0;
}

int main()
{
	int n, m;
	int num1, num2;
	int ans = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &num1, &num2);

		if (CheckUnion(num1, num2))
		{
			if (!ans)
			{
				ans = i + 1;
			}
		}
		else
		{
			Union(num1, num2);
		}
	}

	printf("%d", ans);
	return 0;
}