#include <iostream>
#include <vector>
using namespace std;

int cmp1(int a, int b)
{
	return a > b ? a : b;
}

int cmp2(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// init & input
	int h, w, total = 0;
	vector<int> v;

	cin >> h >> w;

	for (int i = 0; i < w; i++)
	{
		int in;
		cin >> in;
		v.push_back(in);
	}

	// solve
	for (int i = 1; i < w - 1; i++)
	{
		int l = 0, r = 0;
		for (int j = i + 1; j < w; j++)
		{
			r = cmp1(r, v[j]);
		}

		for (int j = i - 1; j >= 0; j--)
		{
			l = cmp1(l, v[j]);
		}

		int water = cmp2(l, r) - v[i];
		if (water > 0)
		{
			total += water;
		}
	}

	// output
	cout << total;

	return 0;
}