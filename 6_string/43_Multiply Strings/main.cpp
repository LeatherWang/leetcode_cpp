
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

string multiply(string num1, string num2)
{
    int n1 = num1.size(), n2 = num2.size();

    vector<int> midRes(n1+n2, 0);
    for(int i=n1-1; i>=0; i--)
    {
        for(int j=n2-1; j>=0; j--)
        {
            int mul = (num1[i]-'0') * (num2[j]-'0');
            int p1 = i+j, p2 = p1+1;
            mul += midRes[p2];

            midRes[p1] += mul/10;
            midRes[p2] = mul%10;
        }
    }

    string res;
    int i=0;
    while((!midRes[i]) && i<midRes.size()) i++;
    for(int j=i; j<midRes.size(); j++)
        res.push_back(char(midRes[j]+'0'));
    return res.empty()?"0":res;
}

int main()
{
    return 0;
}









