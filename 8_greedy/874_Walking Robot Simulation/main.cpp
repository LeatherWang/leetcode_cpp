
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
#include <set>

using namespace std;

// 输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
// 输出: 65
// 解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处
// [-2,-1,8,9,6]
// [[-1,3],[0,1],[-1,5],[-2,-4],[5,4],[-2,-3],[5,-1],[1,-1],[5,5],[5,2]]
int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
{
    int x=0,y=0, thea=1;
    int res=0;
    for(int i=0; i< commands.size(); i++)
    {
        if(commands[i] == -1)
            thea--;
        else if(commands[i] == -2)
            thea++;

        if(thea>2)
            thea = thea-4;
        else if(thea<-2)
            thea = thea+4;

        if(commands[i]>=0)
        {
            int deltaX = commands[i]* (abs(thea)==1?0:(thea==0?1:-1));
            int deltaY =  commands[i]* (abs(thea)==1?thea:0);
            if(deltaX == 0)
            {
                int tmpY = y+deltaY;
                int tmpDis = INT_MAX;
                for(int i=0; i<obstacles.size(); i++)
                {
                    if(obstacles[i][0] == x)
                    {
                        int deltaDis = obstacles[i][1]-y;

                        if(deltaY == 0)
                            cout<<"error: deltaY == 0"<<endl;
                        if(deltaY < 0)
                        {
                            if(deltaY<=deltaDis && deltaDis<0)
                                if(abs(deltaDis) < tmpDis)
                                {
                                    tmpDis = abs(deltaDis);
                                    tmpY = obstacles[i][1]+1; //取最高的那个障碍物
                                }
                        }
                        else if(deltaY >0)
                        {
                            if(0<deltaDis && deltaDis<=deltaY)
                                if(abs(deltaDis) < tmpDis)
                                {
                                    tmpDis = abs(deltaDis);
                                    tmpY = obstacles[i][1]-1; //取最低的那个障碍物
                                }

                        }
                        else
                        {
                            cout<<"error: deltaY == 0"<<endl;
                        }
                    }
                }
                y = tmpY;
            }
            else if(deltaY == 0)
            {
                int tmpX = x+deltaX;
                int tmpDis = INT_MAX;
                for(int i=0; i<obstacles.size(); i++)
                {
                    if(obstacles[i][1] == y)
                    {
                        int deltaDis = obstacles[i][0]-x;
                        if(deltaX == 0)
                            cout<<"error: deltaX == 0"<<endl;
                        if(deltaX < 0)
                        {
                            if(deltaX<=deltaDis &&deltaDis<0)
                                if(abs(deltaDis) < tmpDis)
                                {
                                    tmpDis = abs(deltaDis);
                                    tmpX = obstacles[i][0]+1; //取最高的那个障碍物
                                }
                        }
                        else if(deltaX >0)
                        {
                            if(0<deltaDis && deltaDis<=deltaX)
                                if(abs(deltaDis) < tmpDis)
                                {
                                    tmpDis = abs(deltaDis);
                                    tmpX = obstacles[i][0]-1; //取最低的那个障碍物
                                }
                        }
                        else
                        {
                            cout<<"error: deltaY == 0"<<endl;
                        }
                    }
                }
                x = tmpX;
            }
            else
                cout<<"error: deltaY != 0 && deltaY != 0"<<endl;
        }
        res = max(x*x+y*y, res);
    }
    cout<<res<<endl;
    return res;
}

/*                      if(deltaY < 0)
                        {
                            if(deltaY<=deltaDis<<=0)
                                if(abs(deltaDis) < tmpDis)
                                    tmpY = obstacles[i][1]+1; //取最高的那个障碍物
                        }
                        else if(deltaY >0)
                        {
                            if(0<=deltaDis<=deltaY)
                                if(abs(deltaDis) < tmpDis)
                                    tmpY = obstacles[i][1]-1; //取最低的那个障碍物
                        }
                        else
                        {
                            cout<<"error: deltaY == 0"<<endl;
                        }*/
int main()
{
    vector<int> commands = {4,-1,4,-2,4};
    vector<vector<int>> obstacles = {{2,4}};
    robotSim(commands, obstacles);
    return 0;
}









