#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[2][1001];
vector<int> dist[2];

void dijkstra(int node, int x) 
{
    dist[node][x] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({ 0, x });

    while (!que.empty())
    {
        int cost = que.top().first;
        int cur = que.top().second;
        que.pop();

        if (cost > dist[node][cur]) continue;

        for (int i = 0; i < graph[node][cur].size(); i++) 
        {
            int next = graph[node][cur][i].second;
            int ncost = cost + graph[node][cur][i].first;

            if (ncost < dist[node][next]) 
            {
                dist[node][next] = ncost;
                que.push({ ncost, next });
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    // input & init
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;

        graph[0][u].push_back(make_pair(t, v));
        graph[1][v].push_back(make_pair(t, u));
    }
    dist[0].resize(n + 1, 1e9);
    dist[1].resize(n + 1, 1e9);

    // solve
    dijkstra(1, x);
    dijkstra(0, x);

    int res = 0;
    for (int i = 1; i <= n; i++) 
    {
        res = max(res, dist[0][i] + dist[1][i]);
    }

    // output
    cout << res;

    return 0;
}
