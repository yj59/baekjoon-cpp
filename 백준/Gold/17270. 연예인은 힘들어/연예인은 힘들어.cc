
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[101];
bool notValid[101] = { 0, };

void dijkstra(int start, int* dist)
{
    fill(dist, dist + 101, 1e9);  // 초기화
    notValid[start] = 1;  // 출발 위치는 제외

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dist[cur]) continue;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int calc = cost + graph[cur][i].second;

            if (calc < dist[next])
            {
                dist[next] = calc;
                pq.push(make_pair(-calc, next));
            }
        }
    }
}

int calDistance(int j, int s, int V)
{
    int distJ[101]; // 지헌이의 거리 배열
    int distS[101]; // 성하의 거리 배열
    int sum[101];   // 지헌이와 성하의 거리 합 배열
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> shortest;

    // 다익스트라 실행
    dijkstra(j, distJ); // 지헌이로부터의 최단 거리
    dijkstra(s, distS); // 성하로부터의 최단 거리

    int min = 1e9; // 최단 거리 합의 최소값
    for (int i = 1; i <= V; i++)
    {
        // 지헌이와 성하의 거리 합
        sum[i] = distS[i] + distJ[i];

        // 출발지 또는 성하가 더 빨리 도착하는 곳은 제외
        if (i != j && i != s && sum[i] <= min)
        {
            min = sum[i]; // 최단 거리 합 갱신
        }
        if (distS[i] < distJ[i]) notValid[i] = 1; // 성하가 더 빨리 도착하면 제외
    }

    for (int i = 1; i <= V; i++)
    {
        if (sum[i] == min && !notValid[i])
        {
            shortest.push({ distJ[i], i }); // 거리와 장소를 우선순위 큐에 삽입
        }
    }

    if (!shortest.empty()) return shortest.top().second; // 가장 가까운 장소 반환
    return -1; // 조건을 만족하는 장소가 없는 경우
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, M;
    cin >> V >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    int j, s;
    cin >> j >> s;

    cout << calDistance(j, s, V);

    return 0;
}