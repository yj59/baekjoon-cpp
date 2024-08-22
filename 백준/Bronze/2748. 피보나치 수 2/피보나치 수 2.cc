#include <iostream>
using namespace std;

long long int fib[91];

long long int recur(int n)
{
	if (n == 1 || n == 0) return n;
	if (fib[n]) return fib[n];

	return fib[n] = recur(n - 1) + recur(n - 2);
}

int main()
{
	int n;
	cin >> n;
	cout << recur(n);
}