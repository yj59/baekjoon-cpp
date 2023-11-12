#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool board[51][51];

bool white[8][8] = { 
	{1, 0, 1, 0, 1, 0, 1, 0}, 
	{0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1}, 
	{1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1} };

bool black[8][8] = {
	{0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0}, };


int StartWhite(int stX, int stY)
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[stX + i][stY + j] != white[i][j]) count++;
		}
	}
	return count;
}

int StartBlack(int stX, int stY)
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[stX + i][stY + j] != black[i][j]) count++;
		}
	}
	return count;
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char w;
			cin >> w;
			if (w == 'W') board[i][j] = 1;
			else board[i][j] = 0;
		}
	}

	int count = 65;
	for (int i = 0; i < N - 8 + 1; i++)
	{
		int count_ = 0;
		for (int j = 0; j < M - 8 + 1; j++)
		{
			count_ = min(StartWhite(i, j), StartBlack(i, j));
			if (count > count_)
			{
				count = count_;
			}
		}
	}

	cout << count;
	return 0;
}