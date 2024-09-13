#include <iostream>
#include <cstring>
using namespace std;

bool dp[10001];

void dynamicprogramming(int idx, int num)
{
    for (int i = (idx * 100); i >= 0; i--)
    {
        if (dp[i]) 
        {
            dp[i + num] = true;
        }
    }
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int T, c = 1;
    cin >> T;

    while (T--) 
    {
        int n, num;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
       
        int ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) 
        {
            cin >> num;
            dynamicprogramming(i + 1, num);
        }

        for (int i = 0; i <= (n * 100); i++) 
        {
            if (dp[i]) 
            {
                ans++;
            }
        }

        cout << "#" << c++ << " " << ans << "\n";
    };

    return 0;
}