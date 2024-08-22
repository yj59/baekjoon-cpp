#include <iostream>
using namespace std;
int dp[46];
int fi(int n)
{
	if (n <= 1) return n;
	if (dp[n]) return dp[n];
	dp[n] = fi(n - 1) + fi(n - 2);
	return dp[n];
}

int main()
{
	int n;
	cin >> n;

	cout << fi(n);
}