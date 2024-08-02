#include <set>
#include <vector>
using namespace std;

set<vector<int>> s;

bool find(vector<int> pred) {
    return (s.find(pred) != s.end());
}

bool isValid(const set<vector<int>>& s) {

    for (vector<int> i : s)
    {
        int x = i[0];
        int y = i[1];
        int a = i[2];

        if (a == 0)
        {
            vector<int> pred[3] = { {x,y - 1,0},{x,y,1},{x - 1,y,1} };
            if (y == 0 || find(pred[0]) || find(pred[1]) || find(pred[2])) continue;
            return false;
        }
        else
        {
            vector<int> pred[4] = { {x,y - 1,0},{x + 1,y - 1,0},{x + 1,y,1},{x - 1,y,1} };
            if (find(pred[0]) || find(pred[1]) || (find(pred[2]) && find(pred[3]))) continue;
            return false;
        }
    }

    return true;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {

    vector<vector<int>> answer;

    for (vector<int> i : build_frame)
    {
        vector<int> bf = { i[0],i[1],i[2] };

        if (i[3] == 0)
        {
            s.erase(bf);

            if (!isValid(s)) s.insert(bf);
        }
        else
        {
            s.insert(bf);

            if (!isValid(s)) s.erase(bf);
        }
    }

    for (vector<int> i : s)
    {
        answer.push_back(i);
    }
    return answer;
}
