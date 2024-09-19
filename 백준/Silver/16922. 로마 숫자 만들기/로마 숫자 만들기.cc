#include <iostream>
#include <set>
using namespace std;

int solve(int n)
{
    set<int> s;
    
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n - i; j++)
		{
			for (int k = 0; k <= n - i - j; k++)
			{
				int l = n - i - j - k;
				int calc = i + j * 5 + k * 10 + l * 50;
				s.insert(calc);
			}
		}
	}
	return s.size();
}

int main()
{
	// input
	int n;
	cin >> n;

	// output
	cout << solve(n);
	return 0;
}