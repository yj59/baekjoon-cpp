#include <iostream>

int graph[101][101];

int main()
{
	// init & input
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> graph[i][j];
		}
	}

	// floyd-warshall
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (graph[i][k] && graph[k][j]) graph[i][j] = 1;
			}
		}
	}

	// output
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << graph[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}