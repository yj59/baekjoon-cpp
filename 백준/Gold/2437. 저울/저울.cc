#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	// input & init
	int n;
	cin >> n;

	vector<int> weights(n, 0);
	for (int i = 0; i < n; i++) 
	{
		cin >> weights[i];
	}
	sort(weights.begin(), weights.end());

	int cmp = 1;

	// solve
	for (int i = 0; i < weights.size(); i++) 
	{
		if (weights[i] > cmp) 
		{
			cout << cmp;
			break;
		}
		else 
		{
			cmp += weights[i];
		}

		// output
		if (i == weights.size() - 1) 
		{
			cout << cmp;
		}
	}

	return 0;
}