#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

bool check[101][101];
// vector<string> board;
vector<tuple<int, int, int>> ans;

int solve(vector<string> board, int n, int m)
{
	// find cross
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == '*')
			{
				int len = 0;
				for (int k = 0;; k++)
				{

					if (i + k < n && j + k < m && i - k >= 0 && j - k >= 0)
					{
						if (board[i + k][j] == '*' && board[i][j + k] == '*' && board[i - k][j] == '*' && board[i][j - k] == '*')
						{
							len = k;
						}
						else break;
					}
					else break;
				}

				if (len > 0)
				{
					ans.push_back(make_tuple(i + 1, j + 1, len));

					check[i][j] = 1;
					for (int k = 1; k <= len; k++)
					{
						check[i + k][j] = 1;
						check[i][j + k] = 1;
						check[i - k][j] = 1;
						check[i][j - k] = 1;
					}
				}
			}

			
		}
	}
	
	// isValid
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == '*' && !check[i][j]) return -1;
		}
	}

	return ans.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input & init
	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	// solve
	int info = solve(board, n, m);

	// output
	cout << info << "\n";
	if(info != -1)
	{
		for (int i = 0; i < info; i++)
		{
			tuple<int, int, int> t = ans[i];
			int x, y, l;
			tie(x, y, l) = t;
			cout << x << " " << y << " " << l << "\n";
		}
	}

	return 0;
}