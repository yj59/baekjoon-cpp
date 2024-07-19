#include <iostream>
#include <vector>
using namespace std;

vector<int> seq;
vector<char> res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int el = 1;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		while (el <= num)
		{
			seq.push_back(el++);
			res.push_back('+');
		}
		if (seq.back() == num)
		{
			seq.pop_back();
			res.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << "\n";
	}
	return 0;
}