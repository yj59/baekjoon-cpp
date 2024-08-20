#include <string>
#include <vector>
#include <cmath>
#include <iostream>
 
using namespace std;
 
string answer = "impossible";
bool isArrived = false;
int limit = 0;
pair<int, int> maze_size;
pair<int, int> start;
pair<int, int> goal;
 
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char d[]  = {'d', 'l', 'r', 'u'};
 
int GetDist(pair<int, int> cur)
{
    return abs(goal.first - cur.first) + abs(goal.second - cur.second);
}
 
void dfs(int count, pair<int, int> cur, string path)
{
    if(isArrived) return;
    
    if((limit-count-GetDist(cur)) < 0 || (limit-count-GetDist(cur))%2 == 1) return;
    
    if(count == limit)
    {
        if(cur == goal)
        {
            isArrived = true;
            answer = path;
        }
        
        return;
    }
    
    
    for(int i = 0; i < 4; ++i)
    {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        
        if(nx <= 0 || nx > maze_size.first || ny <= 0 || ny > maze_size.second) continue;
        
        path += d[i];
        dfs(count+1, make_pair(nx, ny), path);
        path.pop_back();
    }
}
 
string solution(int n, int m, int x, int y, int r, int c, int k) 
{
    maze_size = make_pair(n, m);
    start = make_pair(x,y);
    goal = make_pair(r,c);
    limit = k;
    
    dfs(0, start, "");
    
    return answer;
}