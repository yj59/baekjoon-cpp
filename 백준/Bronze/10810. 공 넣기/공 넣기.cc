#include <stdio.h>
int n, m, a, b, c;
int ary[101];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d ", &a, &b, &c);
		for (int j = a; j <= b; j++) ary[j] = c;
	}
	for (int i = 1; i <= n; i++) printf("%d ", ary[i]);
}