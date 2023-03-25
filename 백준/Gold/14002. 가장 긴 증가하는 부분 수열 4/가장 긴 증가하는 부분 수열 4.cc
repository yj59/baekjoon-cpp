#include <stdio.h>
int n;
int A[1000000];
int R[1000000];
int DP[1000000];
int Ans[1000000];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
	
	R[0] = A[1];
	int r = 1;

	for (int i = 2; i <= n; i++)
	{
		if (R[r - 1] < A[i])
		{
			R[r++] = A[i];
			DP[i] = r - 1;
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
		DP[i] = st;
	}

	printf("%d\n", r);

	int a = 0;
	//for (int i = n; i > 1; i--) printf("%d ", DP[i]);
	for (int i = n; i > 0; i--)
	{
		if (DP[i] == r - 1)
		{
			r--;
			Ans[a++] = A[i];
		}
	}
	//printf("\n");
	for (int i = a - 1; i >= 0; i--) printf("%d ", Ans[i]);
	return 0;
}