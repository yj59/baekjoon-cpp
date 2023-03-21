#define INF 987654321

#include <stdio.h>
#include <memory.h>
int W[16][16], DP[16][1 << 16];
int N;

int min(int a, int b)
{
	if (a < b) return a; 
	return b;
}

// dfs => 인접 노드 탐색 후 dp와 비교해 최소 비용 저장
// 
// <W>
//	- W[y]가 비트 자릿수에 추가되어 있다면(1) 탐색 종료 => 이미 탐색한 노드임 => xxx!!!!
//		x => 재귀 돌려서 최소비용 찾아야함 그래도 해야됨
//	- W[node][0] == 0이면 탐색 종료(정점 이동 불가능) else return W[node][0];
//  - 다음 인접 정점 탐색(재귀)
//		=> 연결이 안 되어있거나 W[node][i] == 0
//		=> 이미 방문할 곳일 경우(비트 자릿수에 추가되어 있을 경우) => currentBit & 1<<i
// 
// <dp>
//	- 비교할 최소 비용은 다음 Bit여야 함(탐색할 노드의 정점 추가) 
//		for( int i=0;i<N;i++)
//		=> min(dp[node][currentBit], dfs(node, currentBit | 1<<i) + W[y][x]) 비교하면 될듯
//	- dp가 -1이면 비교하지 않고 즉시 적재(비교할 최솟값 없음)
//		=> 즉시 적재해야 하니까 최댓값(INF)을 대입하고 dp min 비교하면 최솟값 자동으로 적재될듯?

int dfs(int node, int currentBit) 
{
	if (currentBit == ((1 << N) - 1))
	{
		if (W[node][0] == 0) return INF;
		return W[node][0];
	}

	if (DP[node][currentBit] != -1) return DP[node][currentBit];
	else
	{
		DP[node][currentBit] = INF;
		for (int i = 0; i < N; i++)
		{
			if (W[node][i] == 0) continue;
			else if (currentBit & (1 << i)) continue;

			DP[node][currentBit] = min(DP[node][currentBit], dfs(i, currentBit | 1 << i) + W[node][i]);
		}
	}
	return DP[node][currentBit];
}

int main()
{
	memset(DP, -1, sizeof(DP));
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &W[i][j]);

	printf("%d", dfs(0, 1));	// 왜 1? 0번 정점 방문했으니까 체크 => 이렇게 노드 하나씩 비트 움직이면서 1으로 체크해줘야함
}