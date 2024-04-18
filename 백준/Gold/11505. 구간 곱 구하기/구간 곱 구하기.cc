/** [11505/G1] 구간 곱 구하기
* [문제]
* - N개의 수 => 중간에 수 변경
* - 변경된 수열에서 구간 곱 구함
* 
* [입력]
* - 1: 수의 개수 N, 수 변경 횟수 M, 구간 곱 횟수 K
* - 2 ~ N+1: N개의 수
* - N+2 ~ N+M+K+1: 세개의 정수 a, b, c;
*   - a=1: b번째 수를 c로 변경
*   - a=2: 구간 b~c 곱 계산
*/


#include <iostream>
using namespace std;

int arr[1000001];
long long int fenwick[1000001];
int fenwick_zero[1000001];

int limit = 1000000007;

// calculate
long long pow(int x, int n) 
{
    if (n == 1) return x;

    long long half = pow(x, n / 2);

    if (n % 2 == 0) return half * half % limit;
    else return (half * half % limit) * x % limit;
}

long long modInverse(int x) 
{
    return pow(x, limit - 2);
}

long long prefix_multiply(int pos)
{
    if (pos == 0) return 1;

    long long ret = 1;

    while (pos > 0) 
    {
        ret = ret * fenwick[pos] % limit;
        pos &= (pos - 1);
    }

    return ret;
}

// update
void update(int pos, int val, int len)
{
    while (pos < len)
    {
        fenwick[pos] = fenwick[pos] * val % limit;
        pos += (pos & -pos);
    }
}

void update_zero(int pos, int val, int len)
{
    while (pos < len)
    {
        fenwick_zero[pos] += val;
        pos += (pos & -pos);
    }
}

// count
int cnt_zero(int pos)
{
    if (pos == 0) return 0;

    int ret = 0;

    while (pos > 0)
    {
        ret += fenwick_zero[pos];
        pos &= (pos - 1);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // init & input
    int N, M, K;
    cin >> N >> M >> K;

    fill(fenwick, fenwick + N + 1, 1);

    for (int i = 1; i < N + 1; i++) 
    {

        cin >> arr[i];
        if (arr[i] == 0) 
        {
            update_zero(i, 1, N + 1);
            arr[i] = 1;
        }
        else
        {
            update(i, arr[i], N + 1);
        }
    }

    int a, b, c;

    for (int i = 0; i < M + K; i++) 
    {
        cin >> a >> b >> c;

        if (a == 1) // update
        {
            if (c == 0) 
            {
                update_zero(b, 1, N + 1);
            }
            else 
            {
                if (cnt_zero(b) - cnt_zero(b-1) > 0)
                {
                    update_zero(b, -1, N + 1);
                }
                update(b, modInverse(arr[b]), N + 1);
                update(b, c, N + 1);
                arr[b] = c;
            }
        }
        else    // product of interval
        {
            if (cnt_zero(c) - cnt_zero(b) > 0)
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << prefix_multiply(c) * modInverse(prefix_multiply(b - 1)) % limit << "\n";
            }
        }
    }

    return 0;
}