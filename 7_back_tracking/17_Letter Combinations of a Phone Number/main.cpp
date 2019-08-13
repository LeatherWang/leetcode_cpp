
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

void backTracking(string &digits, vector<string> &res, string tmpStr, int index)
{
    if(index == digits.size())
    {
        res.push_back(tmpStr);
        return;
    }
    int num = digits[index]-'0';
    int startChar = 'a'-6+3*num + num/8;

    int endChar = startChar+2;
    if(num == 7 || num == 9)
        endChar++;

    for(int i=startChar; i <= endChar; i++)
    {
        tmpStr.push_back((char)i);
        backTracking(digits, res, tmpStr, index+1);
        tmpStr.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> res;
    if(digits.empty())
        return res;
    backTracking(digits, res, "", 0);
    return res;
}

vector<string> letterCombinations(string digits) {
    if(digits.size()==0)
        return vector<string>();

    map<char,string> numToChar({{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
                                {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}});

    int totalNum=1;
    for(auto &c: digits)
        totalNum*=numToChar[c].size();

    vector<string> res;
    for(int i=0; i<totalNum; i++)
    {
        string s(digits.size(),'*');
        int indexNum=i;
        for(int j=0; j<digits.size(); j++)
        {
            s[j]=numToChar[digits[j]][indexNum%(numToChar[digits[j]].size())];
            indexNum/=numToChar[digits[j]].size();
        }
        res.push_back(s);
    }
    return res;
}

bool isOneBitCharacter(vector<int>& bits) {

    for(int i=0; i<bits.size();)
    {
        if(bits[i] == 0)
        {
            i++;
            if(i==bits.size())
                return true;
        }
        else
        {
            i +=2;
            if(i==bits.size())
                return false;
        }
    }
}

int main()
{
    return 0;
}









