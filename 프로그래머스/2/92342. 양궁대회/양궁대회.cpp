#include <string>
#include <vector>

using namespace std;

vector<int> lions(11, 0);
vector<int> ans;

int maxGap;

void dfs(int n, vector<int>& info, int index, int shot, int scoreLion, int scoreAppeach) 
{
    
    if(index < 0) 
    {
        
        int gap = scoreLion - scoreAppeach;
        
        if(maxGap < gap) 
        {
            maxGap = gap;
            ans = lions;
            
            if(shot > 0) ans[10] = shot;
        }
        return;
    }

    if(shot >= (info[index] + 1)) 
    {
        lions[index] = info[index] + 1;
        dfs(n, info, index - 1, (shot - (info[index] + 1)), scoreLion + (10 - index), scoreAppeach);
        lions[index] = 0;
    }

    if(info[index] > 0) 
    {
        dfs(n, info, index - 1, shot, scoreLion, scoreAppeach + (10 - index));
    } 
    else 
    {
        dfs(n, info, index - 1, shot, scoreLion, scoreAppeach);
    }
    
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    dfs(n, info, 9, n, 0, 0);
        
    if(ans.empty()) return {-1}; else return ans;
}