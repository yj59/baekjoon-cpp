#include<iostream>

using namespace std;

int map[100][100];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int tc = 1; tc <= 10; ++tc)
	{
		// input & init
		cin >> tc;
		int x;

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 2) x = j;
			}
		}

		// code
		for (int i = 99; i >= 0; i--)
		{
			bool visited = 0;
			while (x < 99 && map[i][x + 1])
			{
				visited = 1;
				x++;
			}

			if (!visited)
			{
				while (x > 0 && map[i][x - 1])
				{
					x--;
				}
			}
		}

		// output
		cout << "#" << tc << " " << x << "\n";
	}

	return 0;
}