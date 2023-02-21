#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int l = 0;
		int m = 0;
		while (l!=i)
		{
			printf(" ");
			l++;
		}
		while (m != n - i)
		{
			printf("*");
			m++;
		}
		printf("\n");
	}
}