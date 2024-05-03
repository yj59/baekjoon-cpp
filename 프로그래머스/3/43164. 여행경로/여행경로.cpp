#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[10000] = { 0, };
vector<vector<string>> tickets_;
vector<string> ans;

bool dfs(int cnt, string airport)
{
    ans.push_back(airport);
    
    if(cnt == tickets_.size()) return 1;
    
    for(int i = 0; i < tickets_.size(); i++)
    {
        if(visited[i]) continue;
        if(tickets_[i][0] != airport) continue;
        
        visited[i] = 1;
        bool next = dfs(cnt + 1, tickets_[i][1]);
        
        if(next)
        {
            return 1;
        }
        visited[i] = 0;
        ans.pop_back();
    }
    
    return 0;
}

vector<string> solution(vector<vector<string>> tickets) 
{
    sort(tickets.begin(), tickets.end());
    tickets_ = tickets;
    
    dfs(0, "ICN");
    return ans;
}