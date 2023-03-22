#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
long long int h[200001];

int main()
{
	int n, c;
	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; i++) scanf("%lld", &h[i]);
	sort(h, h + n);

	// 최소 간격은 1, 최대 간격은 정렬한 양 끝 점 사이의 거리
	int st = 1;
	int end = h[n - 1] - h[0];
	int dist = 0;

	while (st <= end)
	{
		int mid = (st + end) / 2;
		int router = 1;
		int ins = h[0];

		for (int i = 1; i < n; i++)
		{
			// 현재 집의 간격이 지정한 공유기의 길이(mid)보다 넓다면 => 카운트!
			// 다음 거리에서 빼줄 기준 집으로 해당 집을 설정함
			// h[i] - h[i - 1]가 왜 안 되냐면 이전 집이 공유기가 설치된 집이 아닐 수도 있음
			if (h[i] - ins >= mid)
			{
				router++;
				ins = h[i];
			}

			// 설치된 공유기의 개수가 c를 넘어가면 => 너무 간격을 좁게 설정한 것임
			// => 간격을 좀 더 넓게 설정해야 하니까, st를 mid+1으로 바꾸어줘야함
		}

		if (router >= c)
		{
			// 현재 길이를 갱신하고 st를 바꾸어주어야 함
			dist = max(dist, mid);
			st = mid + 1;
		}
		else end = mid - 1;
		
	}
	
	printf("%d", dist);
	return 0;
}