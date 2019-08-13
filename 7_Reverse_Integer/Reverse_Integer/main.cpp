
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

int reverse_myself(int x)
{
    long int abs_x=x;
    bool negFlag = false;
    if(abs_x < 0)
    {
        negFlag = true;
        abs_x = abs(abs_x);
    }

    long int temp_x=0;

// 下面是先转换为字符串
//    string mystr = to_string(abs_x);
//    for(auto iter  = mystr.crbegin(); iter!=mystr.crend(); iter++)
//    {
//        temp_x = temp_x*10 + (*iter-'0');
//    }

    for(;abs_x > 0;)
    {
        temp_x = temp_x*10 + (abs_x%10);
        abs_x /=10;
    }

    if(negFlag)
    {
        temp_x *=-1;
        if(temp_x < INT_MIN) //numeric_limits<int>::max()
            return 0;
    }
    else
    {
        if(temp_x > INT_MAX)
            return 0;
    }

    cout<<temp_x<<endl;
    return (int)temp_x;
}

// 方法：弹出和推入数字 & 溢出前进行检查
int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

int main()
{
    reverse(-2147483641);
    return 0;
}









