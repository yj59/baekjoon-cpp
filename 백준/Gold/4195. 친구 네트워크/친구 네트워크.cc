#include <iostream>
#include <string>
#include <map>
using namespace std;

int parent[2000002];
int relation[2000002];

int Find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    int px = Find(x);
    int py = Find(y);

    if (px == py) return;
    if (px < py) parent[py] = px;
    else parent[px] = py;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    while (n--)
    {
        // init & input data
        int f;
        cin >> f;

        for (int i = 0; i < f * 2 + 1; i++)
        {
            parent[i] = i;
            relation[i] = 1;
        }

        int index = 0;
        map<string, int> friends;
        for (int i = 0; i < f; i++)
        {
            string name1, name2;
            cin >> name1 >> name2;

            friends.insert({ name1, index++ });
            friends.insert({ name2, index++ });
            // Union(friends.find(name1)->second, friends.find(name2)->second);

            // cout << friends.find(name1)->second << " " << friends.find(name1)->first << "\n";
            // cout << friends.find(name2)->second << " " << friends.find(name2)->first << "\n";

            // 처음 엮이는 관계이면 Relation Count
            int friend1 = Find(friends.find(name1)->second);
            int friend2 = Find(friends.find(name2)->second);
            // cout << "부모 : " << friend1 << " " << friend2 << "\n";
            // cout << "합산 이전 : " << relation[friend1] << " " << relation[friend2] << "\n";
            if (friend1 != friend2)
            {
                int preNum1 = relation[friend1];
                int preNum2 = relation[friend2];
                relation[friend1] += preNum2;
                relation[friend2] += preNum1;

                // cout << "합산 이후 : " << relation[friend1] << " " << relation[friend2] << "\n";
            }

            // Union
            Union(friends.find(name1)->second, friends.find(name2)->second);

           cout << relation[friend1] << "\n";
        }
    }

    return 0;
}