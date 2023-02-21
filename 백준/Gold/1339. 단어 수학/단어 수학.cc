#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char al[256];
int ans = 0;
int n, m;

int calc(vector<string>& str, vector<char>& l, vector<int>& d) {
	int ls = l.size();
	int sum = 0;

	for (int i = 0; i < ls; i++)
		al[l[i]] = d[i];

	for (string s : str) {
		int now = 0;
		for (char x : s)
			now = now * 10 + al[x];
		sum += now;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<string> str(n);
	vector<char> l;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
		for (char x : str[i])
			l.push_back(x);
	}
	sort(l.begin(), l.end());
	l.erase(unique(l.begin(), l.end()), l.end());
	m = l.size();
	vector<int> d;

	for (int i = 9; i > 9 - m; i--) {
		d.push_back(i);
	}
	sort(d.begin(), d.end());

	do {
		int now = calc(str, l, d);
		if (ans < now)
			ans = now;
	} while (next_permutation(d.begin(), d.end()));
	cout << ans << "\n";
	return 0;
}