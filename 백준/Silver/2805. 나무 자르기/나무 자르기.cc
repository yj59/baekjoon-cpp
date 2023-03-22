#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int N[1000001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) scanf("%lld", &N[i]);
	sort(N, N + n);
	long long int st, mid, end;
	long long int sum, ans = 0;
	st = 0;
	end = N[n - 1];
	while (st <= end)
	{
		mid = (st + end) / 2;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (N[i] > mid) sum += N[i] - mid;
		}
		if (sum >= m)
		{
			st = mid + 1;
			if(mid>ans)ans = mid;
		}
		else if (sum < m) end = mid - 1;
	}
	printf("%lld", ans);
	return 0;
}