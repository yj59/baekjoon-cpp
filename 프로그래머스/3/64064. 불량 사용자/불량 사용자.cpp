#include <bits/stdc++.h>
using namespace std;

bool used[10];
int ret = 0;
set<string> S;

bool possi(string a, string b) 
{
	if (a.length() != b.length()) return 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i] && b[i] != '*') return 0;
	}
	return 1;
}

void dfs(int p, vector<string> user_id, vector<string> banned_id) 
{
	if (p == banned_id.size()) 
	{
		string tmp;
        
		for (int i = 0; i < user_id.size(); i++)
		{
			if (used[i])
			{
				tmp += i + '0';
			}
		}
        
		if (S.find(tmp) != S.end()) return;

		S.insert(tmp);
		ret++;

		return;
	}
    
	for (int i = 0; i < user_id.size(); i++)
	{
		if (!used[i] && possi(user_id[i], banned_id[p]))
		{
			used[i] = true, dfs(p + 1, user_id, banned_id), used[i] = false;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
	dfs(0, user_id, banned_id);
	return ret;
}