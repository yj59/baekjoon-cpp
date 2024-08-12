#include <vector>
#include <iostream>
#include <string>
using namespace std;

int solution(vector<string> arr)
{
	vector<int> arr2 = { stoi(arr[0]) };
	int i = 1;
	int	j = 0;
	int sum = arr2[0];

	while (i < arr.size()) 
	{
		sum += stoi(arr[i + 1]);

		if (arr[i] == "-") 
		{
			arr2.push_back(stoi(arr[i + 1]));
			arr2.push_back(0);
			j += 2;
		}
		else 
		{
			arr2[j] += stoi(arr[i + 1]);
		}

		i += 2;
	}

	for (vector<int>::iterator itr = arr2.begin(); itr != arr2.end(); itr += 1) 
	{
		cout << itr[0] << ",";
	}
	cout << endl;

	int sum2 = arr2[0], min;

	for (int k = 2; k < j + 1; k += 2) 
	{
		sum2 -= arr2[k - 2];
		sum2 += arr2[k - 1];
		sum2 += arr2[k];

		cout << sum2 << endl;

		if (k == 2) min = sum2;
		else if (min > sum2) { min = sum2; }
	}

	return sum - 2 * min;
}