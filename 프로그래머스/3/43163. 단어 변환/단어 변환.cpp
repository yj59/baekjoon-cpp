#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <deque>

using namespace std;

int cnt_notsame(string a, string b)
{
    int cnt=0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]!=b[i])
            cnt++;
    }
    return cnt;
}

int bfs(string begin, string target, vector<string> words)
{
    set <string> visited;
    deque<pair<string,int>>deq;
    
    deq.push_back(make_pair(begin,0));
    visited.insert(begin);
    
    while(deq.empty()!=1){
        string str=deq.front().first;
        int cnt=deq.front().second;
        if(str==target)
            return cnt;
        
        deq.pop_front();
        
        for(int i=0; i<words.size(); i++)
        {
            if(visited.find(words[i])!=visited.end())
                continue;
            
            if(cnt_notsame(str,words[i])!=1)
                continue;
            
            visited.insert(words[i]);
            deq.push_back(make_pair(words[i],cnt+1));
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) 
{
    int answer = bfs(begin,target,words);
    return answer;
}