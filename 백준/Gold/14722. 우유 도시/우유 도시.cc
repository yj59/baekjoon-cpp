#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
typedef pair<int, int> p;

int dir[2][2] = { {0, 1}, {1, 0} };

int N;
int board[1001][1001];
int memo[1001][1001][4];

bool valid(int x, int y) 
{ 
    return 0 <= x && x < N && 0 <= y && y < N; 
}

int nextMilk(int a) 
{
    if (a == 2) return 0;
    return a + 1;
}

int solve(int x, int y, int now) 
{
    if (!valid(x, y)) return 0;

    int& ret = memo[x][y][now + 1];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < 2; ++i) 
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if (valid(nx, ny)) 
        {
            ret = max(ret, solve(nx, ny, now));
            if (board[nx][ny] == nextMilk(now))
            {
                ret = max(ret, solve(nx, ny, nextMilk(now)) + 1);
            }
        }
    }

    return ret;
}

void input()
{
    memset(memo, -1, sizeof(memo));
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    if (board[0][0] == 0) cout << solve(0, 0, 0) + 1 << "\n";
    else cout << solve(0, 0, -1) << "\n";

    return 0;
}
