#include <iostream>
using namespace std;

int card[100001];
bool check[1000001];
int cnt[1000001] = { 0, };

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> card[i];
		check[card[i]] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = card[i] * 2; j < 1000001; j += card[i])
		{
			if (check[j] == 1)
			{
				cnt[card[i]]++;
				cnt[j]--;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << cnt[card[i]] << " ";
	}
	return 0;
}