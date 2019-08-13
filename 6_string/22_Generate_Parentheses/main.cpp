
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

using namespace std;
void insertElement(vector<string> &res, string str, int open, int close, int max)
{
    if(str.size() == max*2)
    {
        res.push_back(str);
        return;
    }

    if(open < max)
        insertElement(res, str+"(", open+1, close, max);
    /** @attention 注意这里形参的改变，并没有改变变量的value，而是在其基础上加上了而已，一次保证递归算法正常运行*/
    if(close < open)
        insertElement(res, str+")", open, close+1, max);
}

vector<string> generateParenthesis(int n)
{
    vector<string> resVec;
    insertElement(resVec, "", 0, 0, n);
    return resVec;
}

int main()
{
    vector<string> myvec = generateParenthesis(3);
    for(string str:myvec)
        cout<<str<<endl;
    return 0;
}









