#include <iostream>
using namespace std;
int d[11];
int n, i, c;
int main()
{
    scanf("%d", &n);
    d[1] = 1; d[2] = 2; d[3] = 4;
    for (i = 4; i < 11; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
        d[i] += d[i - 3];
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &c);
        printf("%d\n", d[c]);
    }
    return 0;
}
