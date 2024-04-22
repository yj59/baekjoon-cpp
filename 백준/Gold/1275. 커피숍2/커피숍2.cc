#include <iostream>
using namespace std;

long long arr[100001];
long long tree[400004];

long long init(int st, int e, int node)
{
	if (st == e) return tree[node] = arr[st];
	
	int mid = (st + e) / 2;

	return tree[node] = init(st, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

long long sum(int st, int e, int node, int l, int r)
{
	if (l > e || r < st) return 0;
	if (l <= st && e <= r) return tree[node];

	int mid = (st + e) / 2;
	return sum(st, mid, node * 2, l, r) + sum(mid + 1, e, node * 2 + 1, l, r);

}

void update(int st, int e, int node, int index, long long dif)
{
	if (index  <st || index > e) return;

	tree[node] += dif;

	if (st == e) return;

	int mid = (st + e) / 2;

	update(st, mid, node * 2, index, dif);
	update(mid + 1, e, node * 2 + 1, index, dif);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input & init
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	init(1, n, 1);

	for (int i = 0; i < q; i++)
	{
		int x, y;
		long long a, b;

		cin >> x >> y >> a >> b;

		if(x < y) cout << sum(1, n, 1, x, y) << "\n";
		else cout << sum(1, n, 1, y, x) << "\n";

		update(1, n, 1, a, b - arr[a]);
		arr[a] = b;
	}

	return 0;
}