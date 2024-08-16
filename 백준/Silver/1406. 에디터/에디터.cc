#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	list<char> lt(s.begin(), s.end());
	list<char>::iterator cursor = lt.end();

	int m;
	cin >> m;

	while (m--)
	{
		char input;
		cin >> input;

		if (input == 'L')
		{
			if (cursor == lt.begin()) continue;
			cursor--;
		}
		else if (input == 'D')
		{
			if (cursor == lt.end()) continue;
			cursor++;
		}
		else if (input == 'B')
		{
			if (cursor == lt.begin()) continue;
			cursor--;
			cursor = lt.erase(cursor);
		}
		else if(input == 'P')
		{
			char c;
			cin >> c;
			lt.insert(cursor, c);
		}
	}

	for (cursor = lt.begin(); cursor != lt.end(); cursor++) cout << *cursor;

	return 0;
}