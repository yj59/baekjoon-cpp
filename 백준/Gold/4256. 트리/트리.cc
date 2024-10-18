#include <iostream>
#include <vector>
using namespace std;

vector<int> pre;
vector<int> in;

void getPostorder(int left, int right, int cur)
{
	for (int i = left; i < right; ++i)
	{
		if (in[i] == pre[cur])
		{
			getPostorder(left, i, cur + 1);
			getPostorder(i + 1, right, cur + 1 + i - left);
			cout << pre[cur] << " ";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int testcase;
	cin >> testcase;

	for (int tc = 0; tc < testcase; tc++)
	{
		// input & init
		int nodeCnt;
		cin >> nodeCnt;

		pre = vector<int>(nodeCnt);
		in = vector<int>(nodeCnt);

		for (int i = 0; i < nodeCnt; i++)
		{
			cin >> pre[i];
		}
		for (int i = 0; i < nodeCnt; i++)
		{
			cin >> in[i];
		}

		// solve
		getPostorder(0, nodeCnt, 0);
		cout << "\n";
	}

	return 0;
}