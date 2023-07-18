#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
#define BMAX 100001
#define INF 987654321
using namespace std;

int n, m;
vector<pair<int, int>> Bus[MAX];
int st, dest;
int dist[MAX];

void Init()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) 
    {
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);
        Bus[a].push_back(make_pair(b, c));
    }

    scanf("%d %d", &st, &dest);
    for (int i = 1; i <= n; i++) 
    {
        dist[i] = INF;
    }
}

void Dijkstra() 
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, st));
    dist[st] = 0;

    while (!pq.empty()) 
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (int i = 0; i < Bus[cur].size(); i++) 
        {
            int next = Bus[cur][i].first;
            int ncost = cost + Bus[cur][i].second;

            if (dist[next] > ncost) 
            {
                dist[next] = ncost;
                pq.push(make_pair(-ncost, next));
            }
        }
    }
    printf("%d\n", dist[dest]);
}

int main() 
{
    Init();
    Dijkstra();
    return 0;
}