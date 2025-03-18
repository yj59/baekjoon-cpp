#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<int, int>> home, chicken;
vector<int> selected;
int result = 1e9;

int getChickenStreet()
{
	int sum = 0;
	for (int i = 0; i < home.size(); i++)
	{
		int comp = 1e9;
		for (int j = 0; j < selected.size(); j++)
		{
			int curChicken = selected[j];
			comp = min(comp, abs(home[i].first - chicken[curChicken].first) + abs(home[i].second - chicken[curChicken].second));
		}
		sum += comp;
	}

	return sum;
}

void getCombination(int idx, int cur, int m)
{
	if (cur == m)
	{
		result = min(result, getChickenStreet());
		return;
	}

	for (int i = idx; i < chicken.size(); i++)
	{
		selected.push_back(i);
		getCombination(i + 1, cur + 1, m);
		selected.pop_back();
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;

			if (num == 1)
			{
				home.push_back({ i, j });
			}
			else if (num == 2)
			{
				chicken.push_back({ i, j });
			}
		}
	}

	getCombination(0, 0, m);

	cout << result;
	return 0;
}