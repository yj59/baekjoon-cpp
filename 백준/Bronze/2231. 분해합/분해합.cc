#include <stdio.h>
int n;
int num[1000001] = { 0, };

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		num[i] = i;
		for (int j = 10; j <= i * 10; j *= 10)
			num[i] += (i % j) / (j / 10);

		if (num[i] == n)
		{
			printf("%d", i);
			return 0;
		}
	}

	printf("0");
}