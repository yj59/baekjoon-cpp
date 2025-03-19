#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int map[9][9];
vector<pair<int, int>> coord;

bool isValid(int x, int y, int num)
{
	for (int i = 0; i < 9; i++)
	{
		if (map[x][i] == num) return 0;
		if (map[i][y] == num) return 0;
	}

	int startx = x / 3 * 3;
	int starty = y / 3 * 3;
	for (int i = startx; i < startx + 3; i++)
	{
		for (int j = starty; j < starty + 3; j++)
		{
			if (map[i][j] == num) return 0;
		}
	}

	return 1;
}

bool solve(int cur)
{
	if (cur == coord.size())
	{
		return 1;
	}

	int x = coord[cur].first;
	int y = coord[cur].second;

	for (int i = 1; i <= 9; i++)
	{
		if (!isValid(x, y, i)) continue;

		map[x][y] = i;
		if(solve(cur + 1)) return 1;
		map[x][y] = 0;
	}

	return 0 ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				coord.push_back({ i, j });
			}
		}
	}

	solve(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}