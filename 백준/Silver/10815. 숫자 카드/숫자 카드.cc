#include <iostream>
#include <algorithm>
using namespace std;

int card[500001];

bool binarySearch(int target, int e)
{
    int st = 0;

    while(st <= e)
    {
        int mid = (st + e) / 2;

        if(card[mid] == target)
        {
            return 1;
        }
        else if(target < card[mid])
        {
            e = mid - 1;
        }
        else    // card[mid] < target
        {
            st = mid + 1;
        }
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // input & init
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
    }

    sort(card, card + n);

    // binary search
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int target;
        cin >> target;
        
        cout << binarySearch(target, n - 1) << " ";
    }

    return 0;
}