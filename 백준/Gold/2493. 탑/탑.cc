#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// init & input
	vector<pair<int, int>> v;

	int n;
	cin >> n;

	// solve
	for (int i = 1; i <= n; i++) 
	{
		int top;
		cin >> top;

		while (!v.empty())
		{
			if (top < v.back().first)
			{
				break;
			}
			v.pop_back();
		}

		// output
		if (v.empty())
		{
			cout << 0 << " ";
		}
		else
		{
			cout << v.back().second << " ";
		}

		v.push_back({ top, i });
	}

	return 0;
}