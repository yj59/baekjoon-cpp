#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<pair<double, double>> v;

double cal(pair<double, double> x, pair<double, double> y, pair<double, double> z)
{
	double ans = 0;
	ans += (x.first * y.second + y.first * z.second + z.first * x.second);
	ans -= (y.first * x.second + z.first * y.second + x.first * z.second);

	return ans/2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		double x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	double ans = 0;

	for (int i = 1; i < v.size(); i++)
	{
		ans += cal(v[0], v[i - 1], v[i]);
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(ans);

	return 0;
}