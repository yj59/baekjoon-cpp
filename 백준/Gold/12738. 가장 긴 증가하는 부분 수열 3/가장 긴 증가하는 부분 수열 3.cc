#include <stdio.h>
int n;
int A[1000000];
int R[1000000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	int r = 0;

	for (int i = 0; i < n; i++)
	{
		if (r == 0 || R[r - 1] < A[i])
		{
			R[r++] = A[i];
			continue;
		}
		int st = 0;
		int end = r;
		while (st <= end)
		{
			int mid = (st + end) / 2;
			if (R[mid] >= A[i]) end = mid - 1;
			else st = mid + 1;
		}
		R[st] = A[i];
	}
	printf("%d\n", r);
	return 0;
}