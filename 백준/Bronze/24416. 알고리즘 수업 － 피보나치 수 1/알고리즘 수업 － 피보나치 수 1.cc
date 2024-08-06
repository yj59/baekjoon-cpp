#include <iostream>
using namespace std;

int recur(int n, int cnt)
{
	cnt++;

	if (n == 1 || n == 2) return 1;
	return recur(n - 1, cnt) + recur(n - 2, cnt);
}

//int dynamic(int n)
//{
//	int d[41];
//	d[1] = d[2] = 1;
//
//	int cnt = 0;
//
//	for (int i = 3; i <= n; i++)
//	{
//		d[i] = d[i - 1] + d[i - 2];
//		cnt++;
//	}
//
//	return cnt;
//}

int main()
{
	int n;
	cin >> n;

	cout << recur(n, 0) << " " << n - 2;

	return 0;
}