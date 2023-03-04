#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int ary[8001] = { 0, };
vector<int> v;

int main()
{
	int n, num, index;
	int av = 0; 
	int mo = 0;
	int min = 4000; 
	int max = -4000;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);

		if (num < min) min = num;
		if (num > max) max = num;

		index = num + 4000;
		ary[index]++; av += num;
		
		if (ary[index] > mo) mo = ary[index];
	}

	int di = (n / 2) + 1;
	int tmp = 0;
	int me = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (tmp < di && (tmp + ary[i]) >= di) me = i-4000;
		tmp += ary[i];
		
		if (ary[i] == mo) v.push_back(i);
	}

	int mode;
	if (v.size() > 1)
	{
		sort(v.begin(), v.end());
		mode = v[1] - 4000;
	}
	else mode = v[0] - 4000;

	int average = round(av / (double)n);

	printf("%d\n%d\n%d\n%d", average, me, mode, max-min);
}