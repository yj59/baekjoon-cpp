#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 50

using namespace std;

int answer = MAX + 1;
bool visited[MAX];
queue<pair<string, int>> q;

bool compareWords(string begin, string word) 
{
    int cnt = 0;
    
    for (int i=0; i<word.length(); i++) {
        if (begin[i] == word[i]) {
            cnt += 1;        
        }
    }
    
    if (cnt == word.length() - 1) return true;
    return false;
}

void bfs(string begin, string target, vector<string> &words) 
{
    int len = words.size();
    q.push({begin, 0});
    
    while (!q.empty()) 
    {
        string word = q.front().first;
        int level = q.front().second;
        q.pop();
        
        if (word == target) 
        {
            answer = min(answer, level);
        }
        
        for (int i=0; i<len; i++) 
        {
            bool isOk = compareWords(word, words[i]);
            if (visited[i] || !isOk) continue;
            
            q.push({words[i], level + 1});
            visited[i] = true;
        }
    }
}

int solution(string begin, string target, vector<string> words) 
{
    vector<string>::iterator iter;
    iter = find(words.begin(), words.end(), target);

    if (iter == words.end()) return 0;
    
    bfs(begin, target, words);
    
    return answer;
}