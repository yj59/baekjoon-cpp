#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

long long int lan[10001];
int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%lld", &lan[i]);
	
	sort(lan, lan + n);

	long long int ans = 0;
	long long int st = 1;
	long long int end = lan[n - 1];
	long long int mid;

	while (st <= end)
	{
		bool cut = false;
		int cnt = 0;
		mid = (st + end) / 2;

		for (int i = 0; i < n; i++)
		{
			cnt += lan[i] / mid;
			if (cnt >= m) cut = true;
		}
		if (cut == true)
		{
			if (ans < mid) ans = mid;
			st = mid + 1;
		}
		else end = mid - 1;
		
	}
	printf("%lld", ans);
	return 0;
}