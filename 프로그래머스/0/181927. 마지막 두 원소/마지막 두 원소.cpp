#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer = num_list;
    
    int last = num_list[num_list.size()-1];
    int comp = num_list[num_list.size()-2];
    
    if(last > comp)
    {
        answer.push_back(last-comp);
    }
    else
    {
        answer.push_back(last*2);
    }
    
    return answer;
}