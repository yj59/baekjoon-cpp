#include <iostream>
#include <vector>
#include <string>
using namespace std;

char cond[10];
bool check[10];
int n;
string s1, s2;

bool comp(int a, int b, char oper)
{
	if ((oper == '<' && a < b) || (oper == '>' && a > b)) return 1;
	return 0;
}

void backtracking(int len, string seq)
{
	if (len == n + 1) 
	{
		if (!s1.size()) s1 = seq;
		else s2 = seq;
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (check[i]) continue;
		if (len && !comp(seq[len - 1], i + '0', cond[len - 1])) continue;

		check[i] = 1;
		backtracking(len + 1, seq + to_string(i));
		check[i] = 0;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cond[i];
	}
	backtracking(0, "");

	cout << s2 << "\n" << s1;
	return 0;
}