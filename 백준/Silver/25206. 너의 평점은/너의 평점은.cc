#include <iostream>
using namespace std;

string m, g;
float c, re, t = 0.0;
float s = 0;

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 20; i++)
	{
		cin >> m >> c >> g;
		if (g == "P") continue;
		s += c;
		if (g == "A+") t += (4.5 * c);
		else if (g == "A0") t += (4.0 * c);
		else if (g == "B+") t += (3.5 * c);
		else if (g == "B0") t += (3.0 * c);
		else if (g == "C+") t += (2.5 * c);
		else if (g == "C0") t += (2.0 * c);
		else if (g == "D+") t += (1.5 * c);
		else if (g == "D0") t += (1.0 * c);
		else if (g == "F");
	}
	re = t / s;
	cout << re;
}