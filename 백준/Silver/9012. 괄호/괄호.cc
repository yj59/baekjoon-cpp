#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		string str;
		cin >> str;
		vector<char> v;
		bool flag = 1;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
				v.push_back('(');
			else
			{
				if (v.empty())
				{
					flag = false;
					break;
				}
				if (v.back() == '(')
				{
					v.pop_back();
				}
			}
		}
		if (!v.empty() || !flag) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}