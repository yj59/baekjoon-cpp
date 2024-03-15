#include <iostream>
using namespace std;

int route[200000], p[200000];
bool visit[200000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> route[i];
        visit[i] = false;
    }
        
    int res = 0;
    int child = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visit[route[i]])
        {
            res++;
            visit[route[i]] = true;
            child = route[i];
        }
        else
        {
            p[child] = route[i];
            child = route[i];
        }

    }
    p[child] = -1;

    cout << res << "\n";
    for (int i = 0; i < res; i++)
    {
        cout << p[i] << " ";
    }
    
    return 0;
}