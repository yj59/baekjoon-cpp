#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str, fire;
	cin >> str >> fire;
	string ans;

	for (int i = 0; i < str.size(); i++)
	{
		ans += str[i];
		if (ans.size() >= fire.size() && ans.substr(ans.size() - fire.size(), ans.size()) == fire)
		{
			ans.erase(ans.size() - fire.size(), ans.size());
		}
	}

	if (ans.empty()) cout << "FRULA\n";
	else cout << ans;

	return 0;
}