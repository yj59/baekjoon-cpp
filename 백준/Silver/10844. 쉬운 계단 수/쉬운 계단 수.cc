#include <iostream>
#define MOD 1000000000
using namespace std;
int d[101][10] = { 0, };
int n, i, j, c = 0;
int main()
{
    for (i = 1; i < 10; i++) d[0][i] = 1;
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (j == 0) d[i][j] = d[i - 1][j + 1];
            else if (j == 9) d[i][j] = d[i - 1][j - 1];
            else d[i][j] += d[i - 1][j - 1] + d[i - 1][j + 1];
            d[i][j] %= MOD;
        }
    }
    for (i = 0; i < 10; i++) c = (c + d[n - 1][i]) % MOD;
    printf("%d", c);
    return 0;
}