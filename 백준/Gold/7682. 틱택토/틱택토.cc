#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool win(string str, char al)
{
	bool result = false;
	int i;

	for (i = 0; i <= 6; i+=3)
	{
		if (str[i] == al && str[i + 1] == al && str[i + 2] == al) result = true;
	}

	for (i = 0; i < 3; i++)
	{
		if (str[i] == al && str[i + 3] == al && str[i + 6] == al) result = true;
	}

	if (str[0] == al && str[4] == al && str[8] == al) result = true;
	if (str[2] == al && str[4] == al && str[6] == al) result = true;

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1)
	{
		string str;
		cin >> str;
		if (str == "end") break;

		int cx = 0, co = 0;
		for (int i = 0; i < 9; i++)
		{
			if (str[i] == 'X') cx++;
			else if (str[i] == 'O') co++;
		}

		bool xwin = win(str, 'X');
		bool owin = win(str, 'O');

		if ((cx == co + 1 && xwin && !owin) || (cx == co && owin && !xwin)) cout << "valid\n";
		else if (!xwin && !owin && cx == 5 && co == 4) cout << "valid\n";
		else cout << "invalid\n";
	}

	return 0;
}

