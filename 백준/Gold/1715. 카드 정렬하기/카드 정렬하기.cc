#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
	int N, ans = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		pq.push(tmp);
	}
	for (int i = 0; i < N-1; i++)
	{
		int t2;
		t2 = pq.top();
		pq.pop();
		t2 += pq.top();
		pq.pop();
		pq.push(t2);
		ans += t2;
	}
	printf("%d", ans);
}