#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

void getElements(string str, unordered_map<string, int>& um) 
{
    for (auto& c : str) c = tolower(c);
    for (int i = 0; i < str.size() - 1; i++) 
    {
        if (!isalpha(str[i]) || !isalpha(str[i + 1])) continue;
        um[str.substr(i, 2)]++;
    }
}

int solution(string str1, string str2) 
{
    int inter_str = 0, union_str = 0;
    unordered_map<string, int> um_str1, um_str2;

    getElements(str1, um_str1);
    getElements(str2, um_str2);

    for (auto element : um_str1) 
    {
        if (um_str2[element.first]) 
        {
            inter_str += min(element.second, um_str2[element.first]);
            
            um_str2[element.first] = max(element.second, um_str2[element.first]);
        }
        else 
        {
            um_str2[element.first] = element.second;
        }
    }

    for (auto element : um_str2) 
    {
        union_str += element.second;
    }

    if (!union_str) return 65536;

    return floor(inter_str * 65536 / union_str);
}