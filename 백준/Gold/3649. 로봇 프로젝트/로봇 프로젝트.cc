#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, n;

	while (cin >> x >> n) 
	{
		x *= 10000000;
		vector<int> v;
		int temp;

		for (int i = 0; i < n; i++) 
		{
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());

		int low = 0;
		int high = v.size() - 1;
		bool flag = false;

		while (low < high) 
		{

			int sum = v[low] + v[high];
			if (sum == x) 
			{
				flag = true;
				break;
			}
			if (sum < x) 
			{
				low++;
			}
			else 
			{ 
				high--;
			}
		}
		if (flag) cout << "yes " << v[low] << ' ' << +v[high] << endl;
		else cout << "danger" << endl;
	}

	return 0;
}