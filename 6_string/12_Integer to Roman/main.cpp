
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

using namespace std;
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
string intToRoman(int num)
{
    vector<vector<char>> vecTmp{
        {'I','V'},{'X','L'},{'C','D'},{'M'}
    };
    string res;
    int i=0;
    while(num)
    {
        int remain = num%10;
        string tmpStr;
        if(remain == 9)
        {
            tmpStr.push_back(vecTmp[i][0]);
            tmpStr.push_back(vecTmp[i+1][0]);
        }
        else if(remain == 4)
        {
            tmpStr.push_back(vecTmp[i][0]);
            tmpStr.push_back(vecTmp[i][1]);
        }
        else
        {
            if(remain/5)
            {
                tmpStr.push_back(vecTmp[i][0]);
                remain -= 5;
            }

            while(remain--)
                tmpStr.push_back(vecTmp[i][1]);
        }
        i++;
        num /= 10;
        res = tmpStr+res;
    }
    return res;
}

int main()
{
    return 0;
}









