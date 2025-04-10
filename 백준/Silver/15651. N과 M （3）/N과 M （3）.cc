#include <iostream>
using namespace std;

int seq[9];
bool visited[9];
int n, m;

void dfs(int cur, int cnt)
{
	
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		seq[cnt] = i;

		visited[i] = 1;
		dfs(i, cnt + 1);
		visited[i] = 0;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	dfs(1, 0);

	return 0;
}