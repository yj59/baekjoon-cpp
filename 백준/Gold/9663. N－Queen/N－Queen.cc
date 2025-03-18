#include <iostream>
using namespace std;

int map[15] = { 0, };
bool col[15] = { 0, };
bool rightdiag[30] = { 0, };
bool leftdiag[30] = { 0, };

int result = 0;
int n;

void memo(bool flag, int i, int c)
{
	col[i] = flag;
	rightdiag[c - i + n - 1] = flag;
	leftdiag[c + i] = flag;
}

void solve(int c)
{
	if (c == n)
	{
		result++;
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (col[i] || rightdiag[c - i + n - 1] || leftdiag[c + i]) continue;

		memo(1, i, c);
		solve(c + 1);
		memo(0, i, c);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;

	solve(0);
	cout << result;
	return 0;
}
