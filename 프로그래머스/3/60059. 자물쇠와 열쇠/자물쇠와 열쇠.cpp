#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> rotation(vector<vector<int>> key, int keysize) 
{
    vector<vector<int>> temp(keysize, vector<int>(keysize));

    for(int i = 0; i < keysize; i++) {
        for(int j = 0; j < keysize; j++) {
            temp[i][j] = key[keysize - j - 1][i];
        }
    }

    return temp;
}

bool isUnlock(int x, int y, vector<vector<int>> key, vector<vector<int>> board, int boardsize, int keysize) 
{

    for(int i = x; i < x + keysize; i++) 
    {
        for(int j = y; j < y + keysize; j++) 
        {
            board[i][j] += key[i-x][j-y];
        }
    }

    for(int i = keysize - 1; i <= boardsize - keysize; i++) 
    {
        for(int j = keysize - 1; j <= boardsize - keysize; j++) 
        {
            if(board[i][j] != 1) 
            {
                return false;
            }
                
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) 
{
    bool answer = false;

    int keysize = (int) key.size();
    int locksize = (int) lock.size();
    int boardsize = locksize + (keysize - 1) * 2;
    
    vector<vector<int>> board(boardsize, vector<int>(boardsize));

    for(int i = keysize - 1; i <= boardsize - keysize; i++) 
    {
        for(int j = keysize - 1; j<= boardsize - keysize; j++) 
        {
            board[i][j] = lock[i - keysize + 1][j - keysize + 1];
        }
    }

    for(int r = 0; r < 4; r++) 
    {
        for(int i = 0; i <= boardsize - keysize; i++) 
        {
            for(int j = 0; j <= boardsize - keysize; j++) 
            {
                if(isUnlock(i, j, key, board, boardsize, keysize)) 
                {
                    return true;
                }
            }
        }

        key = rotation(key, keysize);
    }

    return answer;
}