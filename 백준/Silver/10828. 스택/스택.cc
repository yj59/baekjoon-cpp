#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v;

void Push()
{
	int el;
	cin >> el;
	v.push_back(el);
	return;
}

int Size()
{
	return v.size();
}

bool Empty()
{
	return v.empty();
}

int Pop()
{
	if (Empty()) return -1;
	int el = v.back();
	v.pop_back();
	return el;
}

int Top()
{
	if (Empty()) return -1;
	return v.back();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	while (n--)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push") Push();
		else if (cmd == "pop") cout << Pop() << "\n";
		else if (cmd == "size") cout << Size() << "\n";
		else if (cmd == "empty") cout << Empty() << "\n";
		else cout << Top() << "\n";
	}

	return 0;
}