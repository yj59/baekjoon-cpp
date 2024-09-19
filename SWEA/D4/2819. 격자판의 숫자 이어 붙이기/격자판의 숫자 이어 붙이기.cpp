#include <iostream>
#include <set>
#include <string>
using namespace std;

char board[4][4];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
set<string> s;

void dfs(int x, int y, int length, string curNum)
{
	if (length == 7)
	{
		s.insert(curNum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)	continue;
			
		dfs(nx, ny, length + 1, curNum + board[nx][ny]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for(int tc = 1; tc <= T; tc++)
	{
		// init & input
		s.clear();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> board[i][j];
			}
		}

		// solve
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				dfs(i, j, 0, "");
			}
		}

		cout << "#" << tc << " " << s.size() << "\n";
	}

	return 0;
}