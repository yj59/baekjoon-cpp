#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[50][9];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int> p = { 1,2,3,4,5,6,7,8 };
    int res;

    do 
    {
        vector<int> game = p;
        game.insert(game.begin() + 3, 0);

        int score = 0, j = 0;

        for (int i = 0; i < N; i++) 
        {
            vector<bool> pos(3);
            int out = 0;
            while (out < 3) 
            {
                int cur = a[i][game[j]];
                if (cur == 0) out++;
                else if (cur < 4) 
                {
                    for (int k = 2; k >= 0; k--) 
                    {
                        if (pos[k] == 1) 
                        {
                            int next = k + cur;
                            if (next > 2) score++;
                            else pos[next] = 1;
                            pos[k] = 0;
                        }
                    }
                    pos[cur - 1] = 1;
                }

                else 
                {
                    for (int k = 2; k >= 0; k--) 
                    {
                        score += pos[k];
                        pos[k] = 0;
                    }
                    score++;
                }
                j = (j + 1) % 9;
            }
        }
        
        res = max(res, score);
    } while (next_permutation(p.begin(), p.end()));

    cout << res;
    return 0;
}