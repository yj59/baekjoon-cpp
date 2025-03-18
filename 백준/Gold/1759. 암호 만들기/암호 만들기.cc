#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char alpha[16];
char vowel[] = { 'a', 'e', 'i', 'o', 'u' };
int l, c;

void solve(int cur, string str, int vcnt, int ccnt)
{
	if (str.size() == l)
	{
		if (vcnt >= 1 && ccnt >= 2)
		{
			cout << str << "\n";
		}
		return;
	}

	for (int i = cur; i < c; i++)
	{
		bool flag = false;
		for (int j = 0; j < 5; j++)
		{
			if (alpha[i] == vowel[j])
			{
				flag = true;
				break;
			}
		}

		solve(i + 1, str + alpha[i], vcnt + flag, ccnt + !flag);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> l >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> alpha[i];
	}

	sort(alpha, alpha + c);

	solve(0, "", 0, 0);
	return 0;
}