#include <string> 
#include <vector> 
#include <set> 
using namespace std; 

int N; 

bool next(set<int>& s1, set<int>& s2) 
{ 
    for (int card : s1) 
    { 
        int comb = (N + 1) - card; 
        if (s2.find(comb) != s2.end()) 
        { 
            s1.erase(card);
            s2.erase(comb);
            return true;
        }

    }
    return false;
} 

int solution(int coin, vector<int> cards) 
{
    int answer = 1;
    N = cards.size();
    set<int> init, turn;

    for (int i = 0; i < N / 3; i++)
    {
        init.insert(cards[i]);
    }

    int idx = N / 3;
    while (idx < N)
    {
        for (int i = 0; i < 2; i++)
        {
            turn.insert(cards[idx++]);
        }

        if (init.size() >= 2 && next(init, init))
        {
            answer++;
        }
        else if (init.size() >= 1 && coin >= 1 && next(init, turn))
        {
            answer++;
            coin--;
        }
        else if (coin >= 2 && next(turn, turn))
        {
            answer++;
            coin -= 2;

        }
        else
        {
            break;
        }
    }

    return answer;
}