#include <stdio.h>
int n, m, i, j, a, b, cnt;
int bu[101];
int tmp[101];
int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) bu[i] = i;
	

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		cnt = b - a;
		for (j = 0; j <= cnt; j++) tmp[j] = bu[b--];
		for (j = 0; j <= cnt; j++) bu[a++] = tmp[j];
	}
	for (i = 1; i <= n; i++) printf("%d ", bu[i]);
}