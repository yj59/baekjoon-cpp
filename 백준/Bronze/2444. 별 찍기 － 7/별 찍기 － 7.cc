#include <stdio.h>
int main()
{
	int n, sp, st;
	char s = 32; char b = 42;

	scanf("%d", &n);
	sp = n-1; st = 1;

	while (sp!= -1)
	{
		for (int i = sp; i > 0; i--) printf("%c", s);
		for (int i = 1; i <= st; i++) printf("%c", b);
		printf("\n");
		sp--; st += 2;
	}

	sp = 1; st -= 4;

	while (st > 0)
	{
		for (int i = 1; i <= sp; i++) printf("%c", s);
		for (int i = 1; i <= st; i++) printf("%c", b);
		printf("\n");
		sp++; st -= 2;
	}
	return 0;
}