#include <string>
#include <vector>
#include <cstring>
using namespace std;

long long y = 0;
bool check[64];
bool visited[64];

void dfs(int now, int dx)
{
    visited[now] = true; 
    y += (1LL << now);
    
    for (int next : {now - dx, now + dx})
    {
        if (check[next] && !visited[next])
        {
            dfs(next, dx / 2);
        }
    }
}

vector<int> solution(vector<long long> numbers)
{
    vector<int> answer;
    for (long long x : numbers) 
    {
        bool flag = false;
        memset(check, 0, sizeof(check));

        for (int k = 0; k < 63; k++)
        {
            if ((1LL << k) & x) check[k] = true;
        }

        for (int root : {0, 1, 3, 7, 15, 31})
        {
            if (check[root])
            {
                y = 0;
                memset(visited, 0, sizeof(visited));
          
                dfs(root, (root + 1) / 2);

                if (flag = (x == y)) break;
            }
        }
 
        answer.push_back(flag);
    }
    return answer;
}