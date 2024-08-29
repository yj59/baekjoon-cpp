#include <iostream>
using namespace std;

int arr[12];

int main()
{
	int tc;
	cin >> tc;
	
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i < 12; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	while (tc--)
	{
		int n;
		cin >> n;

		cout << arr[n] << "\n";
	}

	return 0;
}