#include <stdio.h>

int n, m, ni, nn, i, a, b;
int num[101];

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 0; i <= n; i++) num[i] = i;

	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &ni, &nn);
		a = num[ni]; b = num[nn];
		num[ni] = b; num[nn] = a;
	}

	for (i = 1; i <= n; i++) printf("%d ", num[i]);
}