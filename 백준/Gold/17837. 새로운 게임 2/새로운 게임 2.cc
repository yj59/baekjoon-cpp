#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Piece
{
	int y, x, dir;
};

//우, 좌, 상, 하
int dx[] = { 0, 1, -1, 0, 0 };
int dy[] = { 0, 0, -0, -1, 1 };

int map[14][14];
vector<int> num[14][14];
vector<Piece> status;

int n, k;

int blue(int dir)
{
	if (dir == 1) return 2;
	if (dir == 2) return 1;
	if (dir == 3) return 4;
	if (dir == 4) return 3;
}

void simulation(int i, int y, int x, int dir)
{
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	// 파란색
	if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[ny][nx] == 2)
	{
		status[i].dir = blue(status[i].dir);
		ny = y + dy[status[i].dir];
		nx = x + dx[status[i].dir];

		if(nx < 0 || nx >= n || ny < 0 || ny >= n || map[ny][nx] == 2)	return;
	}

	vector<int>& square = num[y][x];
	vector<int>& nsquare = num[ny][nx];
	vector<int>::iterator pos = find(square.begin(), square.end(), i);

	if (map[ny][nx] == 1)
	{
		reverse(pos, square.end());
	}

	for (auto iter = pos; iter != square.end(); iter++)
	{
		status[*iter].y = ny;
		status[*iter].x = nx;

		nsquare.push_back(*iter);
	}
	square.erase(pos, square.end());
	return;
}

bool done()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (num[i][j].size() >= 4) return 1;
		}
	}
	return 0;
}

bool solve()
{
	for (int i = 0; i < status.size(); i++)
	{
		int y = status[i].y;
		int x = status[i].x;
		int dir = status[i].dir;

		simulation(i, y, x, dir);

		if (done()) return 1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input & init
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int x, y, dir;
		cin >> y >> x >> dir;

		num[--y][--x].push_back(i);
		status.push_back({ y, x, dir });
	}

	int turn = 0;
	bool flag = 0;
	while (turn <= 1000)
	{
		turn++;
		if (solve())
		{
			flag = 1;
			break;
		}
	}

	// output
	if (flag) cout << turn << "\n";
	else cout << -1 << "\n";

	return 0;
}