
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

bool detectCapitalUse(string word) {
    if(word.size()==0 || word.size()==1)
        return true;

    bool supper = false;
    if(isupper(word.at(0)))
    {
        if(isupper(word.at(1)))
            supper = true;
    }
    else if(isupper(word.at(1)))
        return false;

    for(int i=2; i<word.size(); i++)
    {
        if( ('A'<=word.at(i) && word.at(i)<='Z') != supper)
            return false;

    }
    return true;
}

int main()
{
    cout<<toGoatLatin("The quick brown fox jumped over the lazy dog")<<endl;
    return 0;
}









