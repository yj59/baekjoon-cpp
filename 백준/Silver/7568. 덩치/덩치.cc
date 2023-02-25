#include <stdio.h>
int n, i, j;
int p[51][2];
int cnt[51] = { 0, };

int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &p[i][0], &p[i][1]);

	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) 
			if (p[i][0] < p[j][0] && p[i][1] < p[j][1]) cnt[i]++;

	for (i = 0; i < n; i++) printf("%d ", cnt[i] + 1);
}