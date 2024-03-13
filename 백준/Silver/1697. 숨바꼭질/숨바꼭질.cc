#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001
int N, K, x;
int cnt[MAX];
bool ch[MAX];
queue<int> q;
int main()
{
	scanf("%d %d", &N, &K);
	q.push(N);
	cnt[N] = 0;
	ch[N] = true;
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		for (int i : {x - 1, x + 1, 2 * x})
		{
			if (i >= 0 && i <= MAX)
			{
				if (ch[i] == false)
				{
					q.push(i);
					ch[i] = true;
					cnt[i] += cnt[x] + 1;
				}
			}
		}
	}
	printf("%d", cnt[K]);
	return 0;
}