
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
int divide(int dividend, int divisor)
{
    if(dividend ==0 || divisor == 0)
        return 0;
    bool sign;
    //sign = dividend>0?(divisor>0?1:-1):(divisor>0?-1:1);
    sign = dividend>0 == divisor>0;
    unsigned int absDvd = abs(dividend);
    unsigned int absDvs = abs(divisor);
    unsigned int res=0, counter=1;

    unsigned int temp = absDvs;
    for(;absDvd >= absDvs;)
    {
        if(absDvd >= temp)
        {
            absDvd -= temp;
            res += counter;
            counter = counter<<1;
            temp = temp<<1;
        }
        else
        {
            temp = temp>>1;
            counter = counter>>1;
        }
    }
    cout<<res<<endl;

    if(!sign)
        return -res;
    else
    {
        return res>INT_MAX?INT_MAX:res;
    }
}

int  NumberOf1(int n) {
         int res = 0;
         unsigned int  m = n;
         while( m!= 0)
         {
             res += m&1;
             m = m>>1;
         }
         return res;
     }

int main()
{
    cout<<NumberOf1(-7)<<endl;
    return 0;
}









