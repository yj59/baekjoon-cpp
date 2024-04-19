#include <iostream>
#include <cmath>
using namespace std;

int min_diff(int n, int arr[][2])
{
	// bitmask
	int cal = 1000000000;

	for (int i = 1; i < (1 << n); i++)
	{
		int mul = 1;
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & 1 << j)
			{
				mul *= arr[j][0];
				sum += arr[j][1];
			}
		}
		cal = min(cal, abs(mul - sum));
	}

	return cal;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// init & input
	int n;
	int arr[10][2];
    
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	// output
	cout << min_diff(n, arr);
	return 0;
}