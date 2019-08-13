
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
#include <set>

using namespace std;
void findIndex(set<int>& res, vector<vector<pair<int,int>>>& myFindings,
               vector<pair<int,int>>& curItems, int wordSize)
{
    if(curItems.size() == wordSize)
    {
        vector<pair<int,int>> tempItems = curItems;
        sort(tempItems.begin(), tempItems.end(),[](const pair<int,int>& ele1, const pair<int,int>& ele2){
            return ele1.first < ele2.first;
        });

        for(int i=0; i < (tempItems.size()-1);i++)
        {
            if((tempItems[i].second) != tempItems[i+1].first)
            {
                cout<<"compare: "<<tempItems[i].first<<" "<<tempItems[i+1].first<<endl;
                return;
            }
        }
        res.insert(tempItems[0].first);
        return;
    }

    for(int i=0; i < myFindings[curItems.size()].size(); i++)
    {
        curItems.push_back(myFindings[curItems.size()][i]);
        cout<<"curItems.size(): "<<curItems.size()<<endl;
        findIndex(res, myFindings, curItems, wordSize);
        curItems.pop_back();
    }
    return;
}
vector<int> findSubstring_myself(string s, vector<string>& words)
{
    vector<int> resVec;
    if(s.empty() || words.empty())
        return resVec;
    vector<vector<pair<int,int>>> myFindings;
    myFindings.resize(words.size());
    for(int i=0; i < words.size(); i++)
    {
        for(int pose=0; (pose = s.find(words[i], pose)) != s.npos; pose++)
        {
            cout<<pose<<endl;
            myFindings[i].push_back(make_pair(pose, pose+words[i].size()));
        }
    }
    cout<<"myFindings size: "<<myFindings.size()<<endl;
    for(vector<pair<int,int>> myvec:myFindings)
    {
        for(pair<int,int> mypair:myvec)
            cout<<mypair.first<<" "<<mypair.second<<"   ";
        cout<<endl;
    }
    vector<pair<int,int>> curItem;
    set<int> myset;
    findIndex(myset, myFindings, curItem, words.size());

    for(int i:myset)
    {
        resVec.push_back(i);
        cout<<i<<endl;
    }
    return resVec;
}


vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ret;
    int N = s.length(), M = words.size();
    if (M == 0 || N < M * words[0].length()) return ret;

    unordered_map<string, int> map, curMap;
    for (string wd : words) ++map[wd];

    int ml = words[0].length();
    string str, tmp;
    for (int i = 0; i < ml; ++i) {
        int count = 0, start = i;
        for (int j = i; j + ml <= N; j += ml) {
            str = s.substr(j, ml);
            if (map.count(str)) {
                ++curMap[str];
                if (curMap[str] <= map[str]) count++;

                while (curMap[str] > map[str]) { //直到将多余的(最前面)那个str删除为止
                    tmp = s.substr(start, ml);
                    --curMap[tmp];
                    start += ml;

                    if (curMap[tmp] < map[tmp]) --count;
                }
                if (count == M) {
                    ret.push_back(start);
                    tmp = s.substr(start, ml);
                    --curMap[tmp];
                    start += ml;
                    count--;
                }
            } else {
                curMap.clear();
                count = 0;
                start = j + ml;
            }
        }
        curMap.clear();
    }

    return ret;
}
int main()
{
    string mystr = "wordgoodstudentgoodword";
    vector<string> words{"good","student"};
    findSubstring(mystr, words);
    return 0;
}









