#include <iostream>
#include <string>
#include <algorithm>
int main()
{
    int dp[1001][1001];
    std::string a, b;
    std::cin >> a >> b;

    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    std::cout << dp[a.length()][b.length()];
    return 0;
}