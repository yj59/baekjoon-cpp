#include <iostream>
#include <queue>
using namespace std;

void solve(int n)
{
	priority_queue<int> pq;
	while (n--)
	{
		int el;
		cin >> el;

		if (el == 0)
		{
			if (pq.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(el);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	solve(n);
	return 0;
}