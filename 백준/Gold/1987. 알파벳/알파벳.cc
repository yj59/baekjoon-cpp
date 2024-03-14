#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, +1 };

char board[20][20];
int alpha[26] = { 0 };
int r, c;

int cnt = 0;

void dfs(int x, int y, int route)
{
    cnt = max(route, cnt);

    for (int i = 0; i < 4; ++i) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 > nx || nx >= r || 0 > ny || ny >= c) continue;

        if (!alpha[((int)board[nx][ny]) - 65])
        {
            alpha[((int)board[nx][ny]) - 65]++;
            dfs(nx, ny, route + 1);

            alpha[((int)board[nx][ny]) - 65]--;
        }
    }
}

int main() 
{
    // input & init
    cin >> r >> c;

    for (int i = 0; i < r; ++i) 
    {
        for (int j = 0; j < c; ++j) 
        {
            cin >> board[i][j];
        }
    }

    alpha[((int)board[0][0]) - 65]++;

    // dfs를 활용해 경로탐색
    dfs(0, 0, 1);

    // output
    cout << cnt;
    return 0;
}