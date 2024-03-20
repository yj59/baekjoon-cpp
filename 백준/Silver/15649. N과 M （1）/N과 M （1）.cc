#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int seq[8];
bool check[8] = { 0, };

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < cnt; i++)
		{
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			seq[cnt] = i;

			check[i] = true;
			dfs(cnt + 1);
			check[i] = false;
		}
	}
}

int main()
{
	// init & input
	cin >> n >> m;

	dfs(0);
}
