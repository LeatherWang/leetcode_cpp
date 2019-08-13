
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
int myAtoi_myself(string str)
{
    if(str.empty()) return 0;
    int parsedNum=0;
    bool notNumFlag = true;
    bool positiveFlag = true;
    for(char ch:str)
    {
        if('0'<=ch && ch<='9')
        {
            notNumFlag = false;
            int num = ch-'0';
            if((positiveFlag && ((parsedNum>INT_MAX/10) || (parsedNum==INT_MAX/10 && num>7)))) //避免益处
                return INT_MAX;
            else if(((!positiveFlag) && ((parsedNum>INT_MAX/10) || (parsedNum==INT_MAX/10 && num>8))))
                return INT_MIN;
            parsedNum = parsedNum*10 + num;
        }
        else
        {
            if(!notNumFlag)
                break;

            if(ch == '+')
            {
                notNumFlag = false;  //避免 "-+1"
                positiveFlag = true;
            }
            else if(ch == '-')
            {
                notNumFlag = false;
                positiveFlag = false;
            }
            else if(ch != ' ')  //避免第一个字符是 +-之外的字符
            {
                return 0;
            }
        }
    }

//    if(!positiveFlag)
//        parsedNum *= -1;
    cout<<parsedNum<<endl;
    return positiveFlag ? parsedNum: -parsedNum;
}

// 别人写的8ms，我自己的20ms，差距啊
int myAtoi(string str)
{
    int i = 0;
    while (str[i] == ' ') /** @attention 既然要寻找第一个非空字符，就这么做啊! 呵呵*/
        ++i;
    bool negative = false;
    if (str[i] == '+' || str[i] == '-') /** @attention 接着判断是否为符号*/
    {
        negative = (str[i] == '-'); //这里也是很简练
        ++i;
    }
    int x = 0;
    for (; str[i] >= '0' && str[i] <= '9' && i < str.size(); ++i) //这条件不能太好了
    {
        int y = str[i] - '0';
        if (x > INT_MAX / 10 || (x == INT_MAX / 10 && y > 7)) //跟我自己的一臂，我太low了吧
        {
            return negative ? INT_MIN : INT_MAX;
        }
        x = x * 10 + y;
    }
    return negative ? -x : x;
}

int main()
{
    myAtoi("-+1");
    return 0;
}









