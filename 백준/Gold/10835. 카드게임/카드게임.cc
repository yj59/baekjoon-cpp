#include <iostream>
#include <cmath>
using namespace std;

int dp[2001][2001] = { 0, };
int lc[2001];
int rc[2001];
int n;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> lc[i];
	for (int i = 0; i < n; i++) cin >> rc[i];
}

int recur(int l, int r)
{
	if (l == n || r == n) return 0;
	if (dp[l][r]) return dp[l][r];

	if (lc[l] <= rc[r]) return dp[l][r] = max(recur(l + 1, r), recur(l + 1, r + 1));
	if (lc[l] > rc[r]) return dp[l][r] = max(dp[l][r], recur(l, r + 1) + rc[r]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	cout << recur(0, 0);

	return 0;
}