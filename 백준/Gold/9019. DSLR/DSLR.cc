#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int t, a, b, num, cal;
int dist[10001];
int pre[10001];
char cmd[10001];
bool visited[10001];
queue<int> q;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &a, &b);

		memset(dist, 0, sizeof(dist));
		memset(pre, 0, sizeof(pre));
		memset(cmd, 0, sizeof(cmd));
		memset(visited, 0, sizeof(visited));

		dist[a] = 0;
		pre[a] = -1;
		visited[a] = true;
		q.push(a);

		while (!q.empty())
		{
			num = q.front();
			q.pop();
			
			cal = num * 2;
			if (cal > 9999) cal = cal % 10000;
			if (visited[cal] == 0)
			{
				q.push(cal);
				dist[cal] = dist[num] + 1;
				pre[cal] = num;
				cmd[cal] = 'D';
				visited[cal] = 1;
			}

			cal = num - 1;
			if (cal == -1) cal = 9999;
			if (visited[cal] == 0)
			{
				q.push(cal);
				dist[cal] = dist[num] + 1;
				pre[cal] = num;
				cmd[cal] = 'S';
				visited[cal] = 1;
			}
			
			cal = (num % 1000) * 10 + num / 1000;
			if (visited[cal] == 0)
			{
				q.push(cal);
				dist[cal] = dist[num] + 1;
				pre[cal] = num;
				cmd[cal] = 'L';
				visited[cal] = 1;
				
			}

			cal = (num / 10) + (num % 10) * 1000;
			if (visited[cal] == 0)
			{
				q.push(cal);
				dist[cal] = dist[num] + 1;
				pre[cal] = num;
				cmd[cal] = 'R';
				visited[cal] = 1;
			}
		}

		string result;
		while (b != a)
		{
			result.push_back(cmd[b]);
			b = pre[b];
		}

		while (!result.empty())
		{
			printf("%c", result.back());
			result.pop_back();
		}
		printf("\n");
	}
}