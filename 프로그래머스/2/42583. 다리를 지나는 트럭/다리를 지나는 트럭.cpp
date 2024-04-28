#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;
    int w = 0;
    int idx = 0;
    int cnt = 1;

    queue<int> q;

    for (int i = 0; i < bridge_length; i++)
    {
        q.push(0);
    }
    
    while (!q.empty())
    {
        w -= q.front();
        q.pop();

        if (idx < truck_weights.size())
        {
            if ((w + truck_weights[idx] <= weight))
            {
                q.push(truck_weights[idx]);
                w += truck_weights[idx];
                idx++;
            }
            else if (q.size() < bridge_length)
            {
                q.push(0);
            }
        }
        cnt++;
        answer++;
    }

    return answer;
}