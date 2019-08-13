
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

vector<vector<string>> findDuplicate(vector<string>& paths)
{
    vector<vector<string>> res;
    unordered_map<string, int> mapRecord;
    for(string str:paths)
    {
        int startPos=str.find(' ', 0);
        int filePos = startPos+1;
        int left;//至少是x.txt
        while((left=str.find('(', filePos+4)) != str.npos)
        {
            int right = str.find(')', left+1);
            string tmpStr = str.substr(left+1, right-left-1);
            auto iter = mapRecord.find(tmpStr);
            if(iter != mapRecord.end())
                res[iter->second].push_back(str.substr(0, startPos)+"/"+str.substr(filePos, left-filePos));
            else
            {
                mapRecord[tmpStr] = res.size();
                res.push_back(vector<string>{str.substr(0, startPos)+"/"+str.substr(filePos, left-filePos)});
            }
            filePos = right+2;
        }
    }

    vector<vector<string>> ans;
    for(int i=0;i<res.size();i++)
        if(res[i].size()>1)
            ans.push_back(res[i]);

    return ans;
}

int main()
{
    //cout<<toGoatLatin("The quick brown fox jumped over the lazy dog")<<endl;
    return 0;
}









