#include <iostream>
using namespace std;
int order[] = { 0, 1, 2 };

int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		if (in == order[cnt % 3])
		{
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}