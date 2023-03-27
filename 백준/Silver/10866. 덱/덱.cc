#include <iostream>
#include <deque>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, l;
	string s;
	deque<int> d;

	cin >> n;
	while(n--)
	{
		cin >> s;
		if (s == "push_front")
		{
			cin >> l;
			d.push_front(l);
		}
		else if (s == "push_back")
		{
			cin >> l;
			d.push_back(l);
		}
		else if (s == "size") 
			cout << d.size() << "\n";
		else if (s == "empty")
			cout << d.empty() << "\n";


		else if (s == "pop_front")
		{
			if (d.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << d.front() << "\n";
			d.pop_front();
		}
		else if (s == "pop_back")
		{
			if (d.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << d.back() << "\n";
			d.pop_back();
		}
		else if (s == "front")
		{
			if (d.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << d.front() << "\n";
		}
		else if (s == "back")
		{
			if (d.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << d.back() << "\n";
		}
	}
	return 0;
}