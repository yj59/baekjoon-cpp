#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct Info 
{
    int x;
    int y;
};

int N, ans = -1;
int visited[51][51];
char MAP[51][51];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
Info Door[2];

void bfs() 
{
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(make_pair(Door[0].x, Door[0].y));

    visited[Door[0].x][Door[0].y] = 1;

    while (q.empty() == 0)
    {
        int size = q.size();
        ans++;

        for (int i = 0; i < size; i++) 
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++) 
            {
                int dist = 1;

                while (1) 
                {
                    int nx = x + dx[j] * dist;
                    int ny = y + dy[j] * dist;

                    if (nx < 0 || N <= nx || ny < 0 || N <= ny)  break;
                    if (MAP[nx][ny] == '*')  break;
                    
                    else if (MAP[nx][ny] == '!' && visited[nx][ny] == 0) 
                    {
                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = 1;
                    }
                    else if (MAP[nx][ny] == '#' && visited[nx][ny] == 0) return;

                    dist++;
                }
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int k = 0;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == '#') 
            {
                Door[k++] = { i, j };
            }
        }
    }

    bfs();
    cout << ans << "\n";

    return 0;
}