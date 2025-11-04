#include <iostream>
#include <vector>
using namespace std;

bool num[1003002];

void pnum()
{
	num[0] = 1;
	num[1] = 1;
	for (int i = 2; i <= 1003001; i++)
	{
		if (num[i]) continue;
		for (int j = i * 2; j <= 1003001; j += i)
		{
			num[j] = 1;
		}
	}
}

int palindrome(int n)
{
	while (1)
	{
		if (num[n])
		{
			n++;
			continue;
		}

		vector<int> v;
		int oper = n;
		while (oper)
		{
			v.push_back(oper % 10);
			oper /= 10;
		}

		bool flag = 1;
		for (int i = 0; i < (v.size() / 2); i++)
		{
			if (v[i] != v[v.size() - 1 - i])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			return n;
		}
		n++;
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;

	pnum();
	cout << palindrome(n);

	return 0;
}