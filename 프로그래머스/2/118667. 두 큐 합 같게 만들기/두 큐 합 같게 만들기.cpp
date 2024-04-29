#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0, sum2 = 0;
    int cnt = 0;
    
    int qsize = queue1.size();
    for (int i = 0; i < qsize; i++)
    {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }

    long long pre = sum1 - sum2;
    long long cur;

    int idx1 = 0, idx2 = 0;
    while (idx1 < queue1.size() && idx2 < queue2.size())
    {
        if (cnt > qsize * 3) return -1;

        cur = sum1 - sum2;
        if (cur == 0) return cnt;

        pre = sum1 - sum2;

        if (cur > 0)
        {
            int el1 = queue1[idx1++];
            queue2.push_back(el1);
            sum1 -= el1;
            sum2 += el1;
        }
        else if (cur < 0)
        {
            int el2 = queue2[idx2++];
            queue1.push_back(el2);
            sum2 -= el2;
            sum1 += el2;
        }
        cnt++;
    }

    return -1;
}