
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <math.h>
#include <list>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> vecTar, vecCandidator;
    for(auto number : nums )
    {
        if(number > target)
            continue;
        vecCandidator.push_back(number);
    }
    sort(vecCandidator.begin(), vecCandidator.end());
    return vecTar;
}

bool compareFunc(const int a, const int b)
{
    return a>b;
}

struct myClass{
    int a;
    bool operator < (const myClass &myClass2)
    {
        return this->a > myClass2.a;
    }
};

int main()
{
    int myints[] = {32,71,12,45,26,80,53,33};
    std::vector<int> myvector (myints, myints+8);

    /**【1】 使用回调函数*/
    std::sort(myvector.begin(), myvector.end(), &compareFunc);
    for(auto item : myvector)
        cout<<item<<" ";
    cout<<endl;

    /**【2】使用lamda表达式*/
    sort(myvector.begin(), myvector.end(), [](const int &i, const int &j){return i<j;});
    for(auto item : myvector)
        cout<<item<<" ";
    cout<<endl;

    /**【3】使用类中的重载 operator < */
    myClass a1, a2;
    a1.a = 3; a2.a = 2;
    bool b = a1<a2;
    cout<< b <<endl;


    return 0;

}
