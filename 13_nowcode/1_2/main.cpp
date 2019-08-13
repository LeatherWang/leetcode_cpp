
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include "time.h"
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iomanip>
#include <sstream>

using namespace std;

class Solution
{
public:
//    void push(int node) {
//        while(!stack1.empty())
//            stack2.push(stack1.pop());
//        stack1.push(node);
//        while(!stack2.empty())
//            stack1.push(stack2.pop());
//    }

//    int pop() {
//        return stack1.pop();
//    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

void replaceSpace(char *str,int length) {
    char *midStr=new char[length];
    int counter = 0;
    for(int i= 0; i< length; i++)
        midStr[i] = str[i];
    for(int i=0; i< length; i++)
    {
        if(midStr[i] == ' ')
        {
            str[counter++] = '%';
            str[counter++] = '2';
            str[counter++] = '0';
        }
        else
            str[counter++] = midStr[i];
    }
}

void replaceSpace_1(char *str,int length) {
    if(str == NULL)
        return;
    int counter = 0;
    int i = 0;
    for(; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
            counter++;
    }

    int newLength = i+2*counter;
    if(newLength+1 > length)
        return;

    char* lp = str + i - 1;
    char* rp = str + newLength - 1;
    *(rp+1) = '\0';
    for(; i>=0; i--)
    {
        if((*lp) == ' ')
        {
            *(rp--) = '0';
            *(rp--) = '2';
            *(rp--) = '%';
        }
        else
            *(rp--) = *lp;
        lp--;
    }
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    int n = input.size();
    if(k>n)
        return vector<int>();
    vector<int> res;
    res.reserve(k);
    priority_queue<int> myque;
    for(int i=0; i<k; i++)
    {
        myque.push(input[i]);
    }

    for(int i=k; i<n; i++)
    {
        if(input[i] < myque.top())
        {
            myque.pop();
            //myque.push(input[i]);
        }
    }

    while(!myque.empty())
    {
        res.push_back(myque.top());
        myque.pop();
        cout<<res.back()<<endl;
    }
    return res;
}

int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        bool up = true;
        if(data[0] > data.back())
            up = false;

        int n = data.size();
        int left = 0;
        int right = n-1;
        int kIndex = -1;
        int cnt = 0;

        //! @attention 下面是错误的写法，如何改正
        while(left < right) //如果使用这种形式，如果data中不包含k，那么将变成死循环
        {
            cnt++;
            int mid = (right-left)/2 + left;
            if(data[mid] == k)
            {
                kIndex = mid;
                break;
            }
            else if(data[mid] < k)
            {
                if(up)
                    left = mid;
                else
                    right = mid;
            }
            else
            {
                if(up)
                    right = mid;
                else
                    left = mid;
            }
        }
        cout<<cnt<<endl;

        if(kIndex == -1)
            return 0;
        int res = 1;
        int i = kIndex;
        while((++i)<n && data[i] == k)
            res++;
        i = kIndex;
        while((--i)>=0 && data[i] == k)
            res++;
        return res;
    }

//vector<vector<int> > FindContinuousSequence(int sum) {
//        deque<int> myque;
//        vector<vector<int>> res;
//        int halfSum = sum/2;
//        int tmpSum=0;
//        for(int i=1; i< halfSum; i++)
//        {
//            myque.push_back(i);
//            tmpSum += i;
//            if(tmpSum == sum)
//            {
//                res.push_back(vector<int>(deque.begin(), deque.end()));
//            }
//            while(tmpSum > sum)
//            {
//                tmpSum -= deque.front();
//                deque.pop_front();
//                if(tmpSum == sum)
//                    res.push_back(vector<int>(deque.begin(), deque.end()));
//            }
//        }
//        return res;
//    }

void recursion(const string &str, string &resStr)
{
    if(str.empty())
        return;
    int n = str.size();
    int i=0;
    for(; str[i] != ' ' && i<n; i++)
    {

    }
    if(i != n)
    {
        recursion(str.substr(i+1, n-i-1), resStr);
        resStr += " " + str.substr(0, i);
    }
    else
        resStr += str.substr(0, i);
}
string ReverseSentence(string str) {
    string resStr;
    recursion(str, resStr);
    return resStr;
}


struct CmpByKeyLength{
    bool operator() (const string &str1, const string &str2)
    {
        return str1.size() > str2.size();
    }
};

bool cmp(const string &str1, const string &str2)
{
    return str1.size() > str2.size();
}

class father
{
public:
    father(){}
    father(int a_):a(a_){}
    int a;
};
class test
{
    public:
    test(){}
    father* mf;
    father* getF(){return mf;}
};

int main()
{
//    auto comp = [](const string& a, const string& b) { return a.length() < b.length(); };
//    map<string, int, decltype(comp)> name_score_map(comp);
//    name_score_map["LiMin"] = 90;
//    name_score_map["ZiLinMi"] = 79;
//    name_score_map["BoB"] = 92;
//    name_score_map.insert(make_pair("Bing",99));
//    name_score_map.insert(make_pair("Albert",86));
//    for (map<string, int>::iterator iter = name_score_map.begin();
//         iter != name_score_map.end();
//         ++iter) {
//        cout << iter->first << endl;
//    }

    //1 2 3 3


//    vector<int> vecScore={1, 2,3,3};


//    auto smallest = std::min_element(std::begin(vecScore), std::end(vecScore));
//    int index = std::distance(std::begin(vecScore), smallest);

//    int num = 1;
//    int size = vecScore.size();
//    int lastSocre = *smallest, lastIndex=index;
//    for(int i=1; i<size; i++)
//    {
//        int curIndex = (index+i)%size;
//        int nextIndex = (index+i+1)%size;
//        if(curIndex == index)
//            break;
//        if(vecScore[lastIndex] < vecScore[curIndex])
//        {
//            if(vecScore[nextIndex] < vecScore[curIndex])
//                vecScore[curIndex] = vecScore[nextIndex] + 1;
//            else
//                vecScore[curIndex] = vecScore[lastIndex] + 1;
//        }
//        lastIndex = curIndex;
//    }

/*
    stringstream ss;
    ss<<setw(4)<<setfill('0')<<12;
    cout<<ss.str()<<endl;
    cout<<setw(4)<<setfill('0')<<1<<endl;
    cout<<2<<endl;*/
/*    test mytest;
    mytest.mf = new father(1);
    cout<<mytest.mf->a<<endl;
    mytest.getF()->a++;
    cout<<mytest.mf->a<<endl;*/



    return 0;
}









