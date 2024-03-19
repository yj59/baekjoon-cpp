#include <iostream>
#include <vector>
using namespace std;

int maxresult = 1e9;
int board[22][22];

vector<int> team1;
vector<int> team2;

int main() 
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}	
	}

	for (int i = 1; i < (1 << N); i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (i & (1 << j))
			{
				team1.push_back(j);
			}
			else
			{
				team2.push_back(j);
			}
		}

		int sum1 = 0;
		int sum2 = 0;
		int team1size = team1.size();
		int team2size = team2.size();

		for (int k = 0; k < team1size - 1; k++) 
		{
			for (int p = k + 1; p < team1size; p++) 
			{
				sum1 += board[team1[k]][team1[p]];
				sum1 += board[team1[p]][team1[k]];
			}
		}

		for (int k = 0; k < team2size - 1; k++) 
		{
			for (int p = k + 1; p < team2size; p++) 
			{
				sum2 += board[team2[k]][team2[p]];
				sum2 += board[team2[p]][team2[k]];
			}
		}
		if (team1.size() && team2.size())
		{
			maxresult = min(maxresult, abs(sum1 - sum2));
		}

		team1.clear();
		team2.clear();
	}
	cout << maxresult;

}