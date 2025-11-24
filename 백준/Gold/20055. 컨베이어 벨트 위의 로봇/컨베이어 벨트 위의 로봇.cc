#include <iostream>
#include <deque>

using namespace std;

deque<bool> robot;
deque<int> belt;
int n, k;

int durability()
{
	int n = 0;
	for (int i = 0; i < belt.size(); i++)
	{
		if (!belt[i]) n++;
	}
	return n;
}

int solve()
{
	int level = 0;
	while (durability() < k)
	{
		level++;

		belt.push_front(belt.back());
		belt.pop_back();

		robot.push_front(robot.back());
		robot.pop_back();

		if (robot[n - 1]) robot[n - 1] = 0;

		for (int i = n - 2; i >= 0; i--)
		{
			if (robot[i] && !robot[i + 1] && belt[i + 1] >= 1)
			{
				robot[i] = 0;
				belt[i + 1]--;
				if (i + 1 == n - 1) continue;
				robot[i + 1] = 1;
			}
		}

		if (belt[0] >= 1 && !robot[0])
		{
			belt[0]--;
			robot[0] = 1;
		}
	}

	return level;
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++)
	{
		int el;
		cin >> el;
		belt.push_back(el);
		robot.push_back(0);
	}

	cout << solve();
	return 0;
}