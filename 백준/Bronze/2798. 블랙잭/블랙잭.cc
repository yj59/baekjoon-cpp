#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, ans = 0;
int arr[101];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	
	sort(arr, arr + n + 1);

	for (int i = n; i > 2; i--)
		for (int j = i - 1; j > 1; j--)
			for (int k = j - 1; k > 0; k--)
				if (arr[i] + arr[j] + arr[k] <= m)
					if (ans < arr[i] + arr[j] + arr[k])
						ans = arr[i] + arr[j] + arr[k];

	printf("%d", ans);
}