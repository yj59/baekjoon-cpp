#include <iostream>
using namespace std;

int table[52];
int list[52][52];

int Find(int x)
{
	if (x == table[x]) return table[x];
	return table[x] = Find(table[x]);
}

void Union(int x, int y)
{
	int px = Find(table[x]);
	int py = Find(table[y]);

	if (px == py) return;
	if (px < py) table[py] = table[px];
	else table[px] = table[py];
}

int main()
{
	int n, m;
	cin >> n >> m;

	// init
	for (int i = 1; i <= n; i++)
	{
		table[i] = i;
	}
	
	// 진실을 아는 사람
	int tn;
	cin >> tn;
	for (int i = 1; i <= tn; i++)
	{
		int input;
		cin >> input;
		table[input] = 0;
	}

	// 리스트 입력 & Union
	for (int i = 0; i < m; i++)
	{
		cin >> list[i][0];
		int stand;
		cin >> stand;
		list[i][1] = stand;
		for (int j = 2; j <= list[i][0]; j++)
		{
			cin >> list[i][j];
			Union(stand, list[i][j]);
		}
	}

	int f = m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= list[i][0]; j++)
		{
			if (Find(table[list[i][j]]) == 0)
			{
				f--;
				break;
			}
		}
	}
	cout << f;
	return 0;
}