#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M, D;
int map[15][15];
bool check[15][15];

pair<int, int> calcArea(int r, int c)
{
    for (int d = 1; d <= D; d++) 
    {
        for (int dc = -(d - 1); dc <= (d - 1); dc++) 
        {
            int dr = -(d - abs(dc));
            int er = r + dr;
            int ec = c + dc;
            if (er < 0 || er >= N || ec < 0 || ec >= M) continue;

            if (map[er][ec] == 1 && !check[er][ec]) 
            {
                return { er, ec };
            }
        }
    }

    return { -1, -1 };
}

int simulate(int pos1, int pos2, int pos3) 
{
    int killCnt = 0;
    vector<int> positions = { pos1, pos2, pos3 };

    memset(check, 0, sizeof(check));

    for (int i = N; i > 0; i--) 
    {
        vector<pair<int, int>> targets;

        for (auto p : positions) 
        {
            targets.push_back(calcArea(i, p));
        }

        for (auto target : targets) 
        {
            if (target == make_pair(-1, -1)) continue;

            int r = target.first;
            int c = target.second;

            if (!check[r][c]) killCnt++;
            check[r][c] = true;
        }
    }

    return killCnt;
}

int setPosition() 
{
    int cnt = 0;

    for (int i = 0; i < M - 2; i++) 
    {
        for (int j = i + 1; j < M - 1; j++) 
        {
            for (int k = j + 1; k < M; k++) 
            {
                cnt = max(cnt, simulate(i, j, k));
            }
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cin >> map[i][j];
        }
    }

    cout << setPosition();

    return 0;
}