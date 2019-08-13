
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
bool isPalindrome_myself(int x)
{
    if(x<0)
        return false;
    string mystr;
    ostringstream ostr;
    ostr<<x;
    mystr = ostr.str();
    int n = mystr.size()-1;
    for(int i=0; i < n-i; i++) //! 注意这个判断条件，很巧妙，并没有讨论数目的奇偶
    {
        if(mystr.at(i) != mystr.at(n-i))
            return false;
    }
    return true;
}

bool isPalindrome(int x)
{
    if(x<0)
        return false;

    int t = x,ans = 0;
    while(t){
        ans = ans*10 + t%10; //int回文数反着读也是这个数，所以...
        t/=10;
    }
    return x == ans;
}

int main()
{
    cout<<isPalindrome(1)<<endl;
    return 0;
}









