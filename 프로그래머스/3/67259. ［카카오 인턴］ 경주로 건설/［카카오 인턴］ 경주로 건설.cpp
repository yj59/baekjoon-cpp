#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pos 
{
    int y, x, cost, dir;
};

int solution(vector<vector<int>> board) 
{
    int answer = 0;
    int n = board.size();

    int deltaY[4] = { -1, 1, 0, 0 };
    int deltaX[4] = { 0, 0, -1, 1 };

    int cost[25][25][4];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 4; ++k)
                cost[i][j][k] = 999999;

    for (int i = 0; i < 4; ++i)
        cost[0][0][i] = 0;

    queue<Pos> q;
    q.push({ 0, 0, 0, -1 });

    while (!q.empty()) 
    {

        Pos now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) 
        {

            int nextY = now.y + deltaY[i];
            int nextX = now.x + deltaX[i];
            int nextDir = i;
            int nextCost = now.cost;

            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || board[nextY][nextX] == 1)
                continue;

            nextCost += 100;
            if (now.dir == 0 || now.dir == 1)
            {
                if (nextDir == 2 || nextDir == 3)
                {
                    nextCost += 500;
                }
            }
            if (now.dir == 2 || now.dir == 3)
            {
                if (nextDir == 0 || nextDir == 1)
                {
                    nextCost += 500;
                }
            }

            if (nextCost < cost[nextY][nextX][nextDir]) 
            {
                cost[nextY][nextX][nextDir] = nextCost;
                q.push({ nextY, nextX, nextCost, nextDir });
            }
        }
    }

    answer = *min_element(cost[n - 1][n - 1], cost[n - 1][n - 1] + 4);
    return answer;
}