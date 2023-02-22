#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;
int d[MAX];
int n, i, j, c;
int main()
{
	d[0] = 0; d[1] = 0;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
	}
	printf("%d", d[n]);
	return 0;
}