#include <iostream>
#include <algorithm>

using namespace std;

int h[300001];
int diff[300001];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // init & input
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (int i = 1; i < n; i++)
    {
        diff[i - 1] = h[i] - h[i - 1];
    }

    sort(diff, diff + n);

    int ans = 0;
    for (int i = 0; i < n - k + 1; i++)
    {
        ans += diff[i];
    }
        
    cout << ans;
    return 0;
}