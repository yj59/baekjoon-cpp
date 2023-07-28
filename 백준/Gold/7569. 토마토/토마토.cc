#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int dz[6] = { 0, 0, 0, 0, 1, -1 };
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };

int tomato[102][102][102];
int d[102][102][102];


int main()
{
    queue<pair<pair<int, int>, int>> q;
    int n, m, h;
    int r = 0;

    scanf("%d %d %d", &m, &n, &h);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                scanf("%d", &tomato[i][j][k]);

                if (tomato[i][j][k] == 1)
                {
                    q.push({ {i, j}, k });
                }
                if (tomato[i][j][k] == 0)
                {
                    d[i][j][k] = -1;
                }
            }
        }
    }

    while (!q.empty())
    {
        int x, y, z;
        z = q.front().first.first;
        x = q.front().first.second;
        y = q.front().second;

        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx, ny, nz;

            nz = z + dz[i];
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (d[nz][nx][ny] >= 0) continue;
            d[nz][nx][ny] = d[z][x][y] + 1;
            q.push({ { nz, nx }, ny });
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (d[i][j][k] == -1)
                {
                    printf("-1\n");
                    return 0;
                }
                r = max(r, d[i][j][k]);
            }
        }
    }

    printf("%d\n", r);
    return 0;
}