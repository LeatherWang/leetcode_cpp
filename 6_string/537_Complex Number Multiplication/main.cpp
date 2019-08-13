
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

// 第一次实现的代码，非常垃圾
string complexNumberMultiply(string a, string b) {
    int arr[4], res[2];
    int l=0;
    bool ispos = true;
    for(int i=1; i<a.size(); i++)
    {
        if(a.at(i) == '+' || a.at(i) == '-')
        {
            if(a.at(i) == '-')
                ispos = !ispos;

            if(isdigit(a.at(i-1)))
                arr[0] = stoi(a.substr(l, i-l));

            if(isdigit(a.at(i+1)))
            {
                l=i+1;
                break;
            }
        }
    }
    arr[1] = (ispos?1:-1) * stoi(a.substr(l, a.size()-l-1));

    l = 0;
    ispos = true;
    for(int i=1; i<b.size(); i++)
    {
        if(b.at(i) == '+' || b.at(i) == '-')
        {
            if(b.at(i) == '-')
                ispos = !ispos;

            if(isdigit(b.at(i-1)))
                arr[2] = stoi(b.substr(l, i-l));

            if(isdigit(b.at(i+1)))
            {
                l=i+1;
                break;
            }
        }
    }
    arr[3] = (ispos?1:-1) * stoi(b.substr(l, b.size()-l-1));

    res[0] = arr[0]*arr[2] - arr[1]*arr[3];
    res[1] = arr[0]*arr[3] + arr[1]*arr[2];

    string ans = to_string(res[0]);
        ans.push_back('+');
    ans +=to_string(res[1]);
    ans.push_back('i');
    return ans;
}

// 第二次改进代码，还是垃圾
string complexNumberMultiply(string a, string b) {
    int coeff[4];
    int i=1;
    for(; i<a.size(); i++)
        if(a.at(i) == '-' || a.at(i) == '+')
            break;
    coeff[0] = stoi(a.substr(0,i));

    i = a.size()-1;
    for(; i>0; i--)
        if(a.at(i) == '-' || a.at(i) == '+')
            break;
    coeff[1] = stoi(a.substr(i,a.size()-1-i));
}

// 排名第一的代码，使用string的库函数啊，find函数!!
string complexNumberMultiply(string a, string b) {
    int a1,a2,b1,b2;
    func(a1,a2,a);
    func(b1,b2,b);
    int n1 = a1*b1-a2*b2;
    int n2 = a1*b2+a2*b1;
    return to_string(n1)+"+"+to_string(n2)+"i";
}

void func(int &a,int &b,string &s){
    size_t plus = s.find('+');
    a = stoi(s.substr(0,plus));
    b = stoi(s.substr(plus+1));
}


int main()
{
    cout<<toGoatLatin("The quick brown fox jumped over the lazy dog")<<endl;
    return 0;
}









