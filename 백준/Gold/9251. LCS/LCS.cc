#include <iostream>
#include <string>
using namespace std;

int dp[1001];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 1; i <= s1.length(); i++)
    {
        int prev = 0;
        for (int j = 1; j <= s2.length(); j++)
        {
            int temp = dp[j];

            if (s1[i - 1] == s2[j - 1]) 
            {
                dp[j] = prev + 1;
            }
            else 
            {
                dp[j] = max(dp[j], dp[j - 1]); 
            }

            prev = temp;
        }
    }

    cout << dp[s2.length()];
    return 0;
}