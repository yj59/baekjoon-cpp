#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
        
    sort(v.begin(), v.end()); 

    int st = 0;
    int e = n - 1;

    int min = 2000000000;
    int ml = 0;
    int mr = 0;

    while (st < e) 
    {
        int sum = v[st] + v[e];

        if (min > abs(sum)) 
        {
            min = abs(sum);
            ml = v[st];
            mr = v[e]; 

            if (sum == 0) break;
        }

        if (sum < 0) 
        {
            st++;    
        }
        else 
        {
            e--;
        }  
    }

    cout << ml << " " << mr;
    return 0;
}