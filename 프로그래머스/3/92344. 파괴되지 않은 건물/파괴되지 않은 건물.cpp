#include <cstring>
#include <vector>

using namespace std;

const int MAX = 1e3;
int dt[MAX + 1][MAX + 1], pf[MAX + 1][MAX + 1];

int solution(vector<vector<int>> board, vector<vector<int>> skill) 
{
    int n = board.size();
    int m = board[0].size();
    memset(dt, 0, sizeof(dt));
    memset(pf, 0, sizeof(pf));

    for (auto s : skill) 
    {
        dt[s[1]][s[2]] += s[5] * (s[0] == 1 ? -1 : 1);
        dt[s[1]][s[4] + 1] += s[5] * (s[0] == 1 ? 1 : -1);
        dt[s[3] + 1][s[2]] += s[5] * (s[0] == 1 ? 1 : -1);
        dt[s[3] + 1][s[4] + 1] += s[5] * (s[0] == 1 ? -1 : 1);
    }

    pf[0][0] = dt[0][0];
    for (int i = 1; i <= n; i++) pf[i][0] = pf[i - 1][0] + dt[i][0];
    for (int i = 1; i <= m; i++) pf[0][i] = pf[0][i - 1] + dt[0][i];
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + dt[i][j];
        }
    }


    int cnt = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (board[i][j] + pf[i][j] > 0) cnt++;
        }
    }
    return cnt;
}