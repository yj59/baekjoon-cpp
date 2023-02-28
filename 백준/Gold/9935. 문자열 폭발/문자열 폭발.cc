#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s, t;
vector<char> st;
bool pop;

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> s >> t;

	for (int i = 0; i < s.size(); i++)
	{
		st.push_back(s[i]);
		if (st.size() >= t.size())
		{
			pop = true;

			for (int j = 0; j < t.size(); j++)
			{
				if (st[st.size() - j - 1] != t[t.size() - j - 1])
				{
					pop = false; break;
				}
			}

			if (pop)
			{
				for (int j = 0; j < t.size(); j++) st.pop_back();
			}
			
		}
	}

	if (st.size() == 0)
	{
		cout << "FRULA";
		return 0;
	}
	for (int i = 0; i < st.size(); i++) cout << st[i];
}