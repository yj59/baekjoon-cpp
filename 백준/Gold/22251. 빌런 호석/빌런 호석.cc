#include <iostream>
using namespace std;

int number[10][7] = {
	{1, 1, 1, 1, 1, 1, 0},  // 0
	{0, 1, 1, 0, 0, 0, 0},	// 1
	{1, 1, 0, 1, 1, 0, 1},	// 2
	{1, 1, 1, 1, 0, 0, 1},	// 3
	{0, 1, 1, 0, 0, 1, 1},	// 4
	
	{1, 0, 1, 1, 0, 1, 1},	// 5
	{1, 0, 1, 1, 1, 1, 1},	// 6
	{1, 1, 1, 0, 0, 0, 0},	// 7
	{1, 1, 1, 1, 1, 1, 1},	// 8
	{1, 1, 1, 1, 0, 1, 1}	// 9
};

int solve(int n, int k, int p, int x)
{
	int result = 0, floor = 0;

	while (floor < n)
	{
		floor++;
		if (floor == x) continue;

		int cnt = 0;
		int digit = x, reverse = floor;

		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (number[digit % 10][j] != number[reverse % 10][j]) cnt++;
			}
			digit /= 10;
			reverse /= 10;
		}
		
		if (cnt > p) continue;
		result++;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 

	int n, k, p, x;
	cin >> n >> k >> p >> x;

	cout << solve(n, k, p, x);
	return 0;
}

