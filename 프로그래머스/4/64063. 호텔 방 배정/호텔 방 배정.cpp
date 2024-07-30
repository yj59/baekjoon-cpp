#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> rooms;
long long Find(long long num)
{
    if (rooms[num] == 0) return num;
    return rooms[num] = Find(rooms[num]);
}

vector<long long> solution(long long k, vector<long long> room_number) 
{
    vector<long long> answer;

    for (auto num : room_number) 
    {
        long long r = Find(num);
        answer.push_back(r);
        rooms[r] = r + 1;
    }
    return answer;
}