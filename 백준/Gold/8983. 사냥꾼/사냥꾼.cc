#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int M, N, L;
vector<int> M_vec;
vector<pair<int, int>> N_vec;

void binarySeach()
{
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		pair<int, int> pos = N_vec[i];
		int x = pos.first;
		int y = pos.second;
		int start = 0;
		int end = M_vec.size() - 1;

		if ((L - y) < 0) continue;

		while (start <= end)
		{
			int mid = (start + end) / 2;

			if (abs(M_vec[mid] - x) <= (L - y))
			{
				answer += 1;
				break;
			}

			if (M_vec[mid] > (L - y + x))
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}

	}
	cout << answer << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> L;
	int val;

	for (int i = 0; i < M; i++)
	{
		cin >> val;
		M_vec.push_back(val);
	}

	int val1, val2;

	for (int i = 0; i < N; i++)
	{
		cin >> val1 >> val2;
		N_vec.push_back(pair<int, int>(val1, val2));
	}

	sort(M_vec.begin(), M_vec.end());
	binarySeach();
}