#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;
int d[MAX];
int h[MAX];
int n, i, j, c;
int main()
{
	d[0] = 0; d[1] = 0;
	h[1] = -1;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		h[i] = i - 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
		{
			d[i] = min(d[i], d[i / 2] + 1);
			h[i] = i / 2;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1)
		{
			d[i] = min(d[i], d[i / 3] + 1);
			h[i] = i / 3;
		}
	}
	printf("%d\n", d[n]);
	while (n != -1)
	{
		printf("%d ", n);
		n = h[n];
	}
	return 0;
}