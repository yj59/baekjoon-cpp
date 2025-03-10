#include <iostream>
#include <algorithm>

using namespace std;

bool solve(string s, string t)
{
	if (s == t) return 1;
	if (s.size() >= t.size()) return 0;

	string nt = "";

	if (t[t.size() - 1] == 'A')
	{
		nt = t;
		nt.pop_back();

		if (solve(s, nt)) return 1;
	}

	if (t[0] == 'B')
	{
		nt = t;
		nt.erase(nt.begin());
		reverse(nt.begin(), nt.end());

		if (solve(s, nt)) return 1;
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s, t;
	cin >> s >> t; 

	cout << solve(s, t);
	return 0;
}