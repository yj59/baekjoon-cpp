#include <iostream>
using namespace std;

int a[202];
bool robot[202] = { 0, };
int up, down, cnt;
bool front;

void unload()
{
	if (!robot[down]) return;

	robot[down] = false;
	return;
}

void rotation(int n)
{
	if (up <= 1) up = 2 * n;
	else up--;

	if (down <= 1) down = 2 * n;
	else down--;

	unload();
}

void move(int n)
{
	if (!front) return;

	int cur = down;
	for (int i = 1; i < n; i++)
	{
		int cur = down - i;
		if (cur <= 0) cur = 2 * n + (down - i);

		if (!robot[cur]) continue;

		int next = cur + 1;
		if (next > 2 * n) next = 1;
		if (!a[next] || robot[next]) continue;

		robot[cur] = false;
		robot[next] = true;
		a[next]--;

		if (!a[next]) cnt++;
	}

	unload();
	return;
}

void load(int n)
{
	if (a[up] == 0 || robot[up] == 1) return;

	robot[up] = true;
	a[up]--;

	if (!front) front = 1;
	if (a[up] == 0) cnt++;
}

int solve(int n, int k)
{
	cnt = 0;
	up = 1;
	down = n;
	front = false;

	int step = 1;

	while (1)
	{
		rotation(n);
		move(n);
		load(n);

		if (cnt >= k) return step;

		step++;
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> a[i];
	}

	cout << solve(n, k);
	return 0;
}