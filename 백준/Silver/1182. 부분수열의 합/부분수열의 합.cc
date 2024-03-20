#include <iostream>

int n, s;
int cnt = 0;
int seq[20];
bool check[20];

void dfs(int sum, int idx)
{
	if (n == idx)
	{
		if (sum == s)
		{
			cnt++;
		}
		return;
	}

	dfs(sum, idx + 1);
	dfs(sum + seq[idx], idx + 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		std::cin >> seq[i];
	}

	// dfs & backTracking
	dfs(0, 0);
	if (!s)
	{
		cnt--;
	}

	std::cout << cnt;

	return 0;
}