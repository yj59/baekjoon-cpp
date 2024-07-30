#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> um;
long long Find(long long n)
{
    if (um[n] == 0) return n;
    return um[n] = Find(um[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) 
{
    vector<long long> answer;

    for (long long n : room_number) 
    {
        long long room = Find(n);
        answer.push_back(room);
        um[room] = room + 1;
    }
    
    return answer;
}