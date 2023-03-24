#include <stdio.h>
int n, m = 1;
int main() {
	scanf("%d", &n);
	while (n > m) 
	{
		n -= m;
		m++;
	}
	if (m % 2 == 1)
		printf("%d/%d", m + 1 - n, n);
	else
		printf("%d/%d", n, m + 1 - n);
}