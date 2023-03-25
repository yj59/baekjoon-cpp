#include <stdio.h>
int n;
long long int A[1000000];
long long int R[1000000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &A[i]);
	int r = 0;

	for (int i = 0; i < n; i++) 
	{
		if (r == 0 || R[r-1] < A[i])
		{
			R[r++] = A[i];
			continue;
		}
		else 
		{
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
	}
	printf("%d", r);
	return 0;
}