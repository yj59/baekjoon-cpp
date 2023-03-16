#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int list[500000];
long long cnt = 0;

long long merge(int st, int e) {
    if (st == e) return 0;

    vector<int> tmp;
    int m = (st + e) / 2;
    merge(st, m);
    merge(m + 1, e);

    int left = st;
    int right = m + 1;
    
    while (left <= m || right <= e) 
    {
        if (left <= m && (right > e || list[left] <= list[right]))
            tmp.push_back(list[left++]);
        else
        {
            cnt += m - left + 1;
            tmp.push_back(list[right++]);
        }
    }

    for (int i = st; i <= e; i++) 
        list[i] = tmp[i - st];

    return cnt;
}

int main() {
    int n;
    long long result;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    result = merge(0, n - 1);
    printf("%lld", result);
    return 0;
}