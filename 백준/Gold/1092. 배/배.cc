#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> crane;
vector<int> box;

bool desc(int a, int b) 
{
	return a > b;
}

int greedy(int n, int m)
{
	if (crane[0] < box[0]) return -1;
	int cnt = 0;

	while (!box.empty())
	{
		cnt++;

		for (int i = 0; i < crane.size(); i++)
		{
			for (int j = 0; j < box.size(); j++)
			{
				if (crane[i] >= box[j])
				{
					box.erase(box.begin() + j);
					break;
				}
			}
		}
	}

	return cnt;
}

int main()
{
	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		crane.push_back(tmp);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		box.push_back(tmp);
	}

	sort(crane.begin(), crane.end(), greater<>());
	sort(box.begin(), box.end(), greater<>());

	cout << greedy(n, m);

	return 0;
}