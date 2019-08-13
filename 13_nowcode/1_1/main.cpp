
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include "time.h"

using namespace std;

bool Find(int target, vector<vector<int> > array) {
        int m = array.size(), n = array[0].size();
        for(int i=0; i< n; i++)
        {
            if(array[0][i] <= target)
            {
                for(int j=0; j< m; j++)
                {
                    if(array[j][i] == target)
                        return true;
                }
            }
            else
                return false;
        }
        return false;
    }
int main()
{
    return 0;
}









