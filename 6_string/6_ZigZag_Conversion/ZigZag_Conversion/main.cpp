
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <math.h>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory.h>

using namespace std;
//! @attention 调试日志
//! 1. 考虑除0的情况
//! 2. 考虑行数为1和2情况
string convert(string s, int numRows)
{
    int n = s.size();
    string reOrderedString;
    reOrderedString.reserve(s.size());
    int numCols;
    if(numRows != 1) //考虑行数等于1
    {
        numCols = n/(2*numRows - 2)*(numRows - 1); /** @attention 考虑除0的情况啊*/
        int remainder = n%(2*numRows - 2);
        if(remainder > 0)
        {
            numCols++;
            if(remainder > numRows)
                numCols += remainder-numRows;
        }
    }
    else
    {
        return s;
    }

    /** @attention 二维数组*/
    char **myary = new char *[numRows];
    for(int i=0; i<numRows; i++)
    {
        myary[i] = new char [numCols];
        memset(myary[i], 0, numCols*sizeof(char)); //初始化为0
    }

    int rowIndex=0, strIndex=0;
    bool indexModel = true;
    for(int j=0; j<numCols && strIndex<s.size(); j++)
    {
        if(indexModel)
        {
            for(; 0<=rowIndex && rowIndex<numRows && strIndex<s.size(); rowIndex++)
            {
                myary[rowIndex][j] = s.at(strIndex);
                strIndex++;
            }
            if(rowIndex == numRows)
            {
                rowIndex--;
                if(rowIndex != 1)  //考虑行数为2的情况
                    indexModel = false;
                else
                    rowIndex = 0;
            }
        }
        else
        {
            rowIndex--;
            myary[rowIndex][j] = s.at(strIndex);
            if(rowIndex == 1)
            {
                rowIndex = 0;
                indexModel = true;
            }
            strIndex++;
        }
    }

    for(int i=0; i<numRows; i++)
    {
        for(int j=0; j<numCols; j++)
        {
            if(myary[i][j] != 0)
                reOrderedString.push_back(myary[i][j]);
            //cout<<myary[i][j]<<" "<<ends;
        }
        cout<<endl;
    }
    return reOrderedString;
}

// 方法一：按行排序
// 只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变
string convert_row_ordered(string s, int numRows)
{
    if (numRows == 1) return s;

    bool bGoingDown = false;
    int rowIndex = 0;
    vector<string> vecRowStr(min(numRows, (int)s.size()));

    for(char ch:s)
    {
        vecRowStr[rowIndex].push_back(ch);
        if((0 == rowIndex) || (rowIndex == (vecRowStr.size()-1))) bGoingDown = !bGoingDown;
        bGoingDown ? rowIndex++ : rowIndex--;
    }

    string resultStr;
    for(string subStr:vecRowStr) resultStr +=subStr;
    return resultStr;
}

int main()
{
    string mtstr="PAYPALISHIRING";
    cout<<convert(mtstr, 2)<<endl;
    cout<<convert_row_ordered(mtstr, 2)<<endl;
    return 0;
}









