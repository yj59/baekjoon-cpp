#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<string, int>> v;
vector<pair<int, string>> prefix;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		v[i] = { tmp, i };
	}

	sort(v.begin(), v.end());

	int len = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int m = 0;

		for (int j = 0; j < v[i].first.size(); j++)
		{
			if (v[i].first[j] != v[i + 1].first[j])	break;
			m++;
		}

		if (v[i].first == v[i + 1].first || m < len) continue;
		if (m > len)
		{
			prefix.clear();
			len = m;
		}

		prefix.push_back({ v[i].second,v[i].first });
		prefix.push_back({ v[i + 1].second,v[i + 1].first });
	}

	sort(prefix.begin(), prefix.end());

	string s = prefix[0].second;
	string t;

	for (int i = 1; i <= prefix.size(); i++)
	{
		if (prefix[i].second == s)	continue;
		if (s.substr(0, len) != prefix[i].second.substr(0, len)) continue;

		t = prefix[i].second;
		break;
	}

	cout << s << "\n" << t;
	return 0;
}