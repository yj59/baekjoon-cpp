#include <stdio.h>
int n, a, b, arr = 1001;
int koi[101][2];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &koi[i][0], &koi[i][1]);
		if (koi[i][0] <= koi[i][1])
			if (arr > koi[i][1]) arr = koi[i][1];
	}
	if (arr == 1001) printf("-1");
	else printf("%d", arr);
}