#include <iostream>
using namespace std;

bool visited[1000001];
int memo[1000001];

void recur(int n, int cnt)
{
	if (visited[n] && memo[n] < cnt) return;

	visited[n] = 1;
	memo[n] = cnt;

	if (n == 1) return;

	if (n % 3 == 0) recur(n / 3, cnt + 1);
	if (n % 2 == 0) recur(n / 2, cnt + 1);
	recur(n - 1, cnt + 1);
}

int main()
{
	int n;
	cin >> n;

	recur(n, 0);
	cout << memo[1];

	return 0;
}