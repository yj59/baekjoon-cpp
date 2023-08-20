#include <iostream>
using namespace std;

bool room[50][50];
bool visited[50][50] = { 0, };
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M;
int cnt;
int r, c, d;

void dfs()
{
    for (int i = 0; i < 4; i++)
    {
        int nd = (d + 3 - i) % 4;
        int nr = r + dx[nd];
        int nc = c + dy[nd];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M || room[nr][nc] == 1) continue;
        
        if (room[nr][nc] == 0 && visited[nr][nc] == 0)
        {
            visited[nr][nc] = 1;
            r = nr;
            c = nc;
            d = nd;
            cnt++;
            dfs();
        }
    }
    int pd;
    if (d > 1) pd = d - 2;
    else pd = d + 2;
    int pr = r + dx[pd];
    int pc = c + dy[pd];
    if (pr >= 0 && pr <= N || pc >= 0 || pc <= M)
    {
        if (room[pr][pc] == 0)
        {
            r = pr;
            c = pc;
            dfs();
        }
        else
        {
            cout << cnt;
            exit(0);
        }
    }
}

int main()
{
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];
        }
    }

    visited[r][c] = 1;
    cnt++;

    dfs();

    return 0;
}