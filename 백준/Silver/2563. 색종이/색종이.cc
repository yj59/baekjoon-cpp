#include <stdio.h>
bool d[100][100] = { 0, };
int x, y, i, j, k, cnt, b = 0;
int main()
{
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++)
	{
		scanf("%d %d", &x, &y);
		for (j = 0; j < 10; j++)
		{
			for (k = 0; k < 10; k++)
			{
				if (d[x + j][y + k] == false)
				{
					d[x + j][y + k] = true;
					b++;
				}
			}
		}
	}
	printf("%d", b);
}