
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <math.h>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory.h>
#include <climits>
#include <sstream>
#include <set>

using namespace std;

void dfs(vector<vector<char>>& board, vector<int>& click)
{
    bool haveMine=false;
    int mineNum = 0;
    for(int i=click[0]-1; i<click[0]+2; i++)
    {
        if(i<0 || i>=board.size())
            continue;
        for(int j=click[1]-1; j<click[1]+2; j++)
        {
            if(j<0 || j>=board[0].size())
                continue;
            if(board[i][j] == 'M' || board[i][j] == 'X')
            {
                mineNum++;
                haveMine = true;
            }
        }
    }

    if(haveMine)
    {
        if(board[click[0]][click[1]] == 'E')
            board[click[0]][click[1]] = mineNum+'0';
        else
            board[click[0]][click[1]] = 'X';
        return;
    }
    else
    {
        board[click[0]][click[1]] = 'B';
        for(int i=click[0]-1; i<click[0]+2; i++)
        {
            if(i<0 || i>=board.size())
                continue;
            for(int j=click[1]-1; j<click[1]+2; j++)
            {
                if(j<0 || j>=board[0].size())
                    continue;
                if(board[i][j] != 'E' && board[i][j] != 'M')
                    continue;

                vector<int> myvec{i,j};
                dfs(board, myvec);
            }
        }
    }
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
{
    if(board.empty() || click.empty())
        return board;
    dfs(board, click);
    return board;
}
int main()
{
    return 0;
}









