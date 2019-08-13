
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

//Input: "(()(()))"
//Output: 6

int scoreOfParentheses(string S) {
    int res = 0, layers = 0;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == '(') layers++; else layers--;
        if (S[i] == '(' && S[i + 1] == ')') res += 1 << (layers - 1);
    }
    return res;
}

int main()
{
    return 0;
}









