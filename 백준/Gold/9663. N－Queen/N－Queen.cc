#include <iostream>
using namespace std;

int map[15];
int n, cnt = 0;

void backtracking(int depth)
{
	if (depth == n) 
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		bool check = 1;
		map[depth] = i;

		for (int j = 0; j < depth; j++)
		{
			if (map[depth] == map[j] || depth - j == abs(map[depth] - map[j])) 
			{
				check = 0;
				break;
			}
		}

		if(check) backtracking(depth + 1);
	}
}

int main()
{
	cin >> n;

	backtracking(0);

	cout << cnt;
	return 0;
}