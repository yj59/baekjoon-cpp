#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

bitset<1003002> num;

void pnum()
{
	num[0] = 1;
	num[1] = 1;
	for (int i = 2; 1LL * i * i <= 1003001; i++)
	{
		if (num[i]) continue;
		for (int j = i * 1LL * i; j <= 1003001; j += i)
		{
			num[j] = 1;
		}
	}
}
inline bool isPal(int n)
{
	int num = n;
	int reverse = 0;
	while (n)
	{
		reverse = reverse * 10 + n % 10;
		n /= 10;
	}

	return num == reverse;
}

int digit(int n)
{
	if (n == 0) return 1;
	int d = 0;
	while (n > 0)
	{
		n /= 10;
		++d;
	}
	return d;
}

int palindrome(int n)
{
	if (n <= 2) return 2;
	if (n % 2 == 0) n++;
	while (1)
	{
		int d = digit(n);
		if (d % 2 == 0 && n != 11)
		{
			int next = 1;
			for (int i = 0; i < d; i++)
			{
				next *= 10;
			}
			n = next + 1;
			continue;
		}
		if (!num[n] && isPal(n)) return n;
		n += 2;
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