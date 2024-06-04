#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;

    cin >> T;
    for (int t = 0; t < T; t++)
    {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string x;
        cin >> x;

        deque<int> ret;
        string el;

        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] == '[') continue;
            else if ('0' <= x[i] && x[i] <= '9')
            {
                el += x[i];
            }
            else if (x[i] == ',' || x[i] == ']')
            {
                if (!el.empty())
                {
                    ret.push_back(stoi(el));
                    el.clear();
                }
            }
        }
        bool err = false;
        bool f = true;
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == 'R') f = !f;
            else 
            {
                if (ret.empty())
                {
                    err = true;
                    cout << "error\n";
                    break;
                }
                else
                {
                    if (f) ret.pop_front();
                    else ret.pop_back();
                }
            }
        }
        if (!err)
        {
            if (f)
            {
                cout << "[";
                int l = ret.size();
                for (int i = 0; i < l; i++)
                {
                    cout << ret.front();
                    ret.pop_front();
                    if (!ret.empty()) cout << ",";
                }
                cout << "]\n";
            }
            else
            {
                cout << "[";
                int l = ret.size();
                for (int i = 0; i < l; i++)
                {
                    cout << ret.back();
                    ret.pop_back();
                    if (!ret.empty()) cout << ",";
                }
                cout << "]\n";
            }
        }
    }
}