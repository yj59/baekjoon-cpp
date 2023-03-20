#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char m[64][64];
int n, i;
void d(int y, int x, int size)
{
	char head = m[y][x];
	bool o = true;
	int dx, dy;
	for (dy = 0; dy < size; dy++) {
		for (dx = 0; dx < size; dx++) {
			if (head != m[y + dy][x + dx]) {
				o = false;
				break;
			}
		}
		if (o == false) break;
	}

	if (o) printf("%c", head);
	else {
		int half = size / 2;

		printf("(");
		d(y, x, half);
		d(y, x + half, half);
		d(y + half, x, half);
		d(y + half, x + half, half);
		printf(")");
	}
}
int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%s", m + i);
	d(0, 0, n);
	return 0;
}