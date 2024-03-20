#include <iostream>
#include <algorithm>
using namespace std;

int arr[8];
int seq[8];
bool check[8] = { 0, };
int n, m;

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

	int dupe = 0;
	for (int i = 0; i < n; i++)
	{
		if (!check[i] && dupe != arr[i])
		{
			seq[cnt] = arr[i];
			dupe = seq[cnt];

			check[i] = true;
			dfs(cnt+1);
			check[i] = false;
		}
	}
}

int main()
{
	// init & input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	dfs(0);
}
