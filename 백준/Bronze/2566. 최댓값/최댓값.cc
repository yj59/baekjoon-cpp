#include <stdio.h>
int main()
{
	int x, y, t, n = 0;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			scanf("%d", &t);
			if (n <= t)
			{
				n = t;
				x = i; y = j;
			}
		}
	}
	printf("%d\n%d %d", n, x, y);
}