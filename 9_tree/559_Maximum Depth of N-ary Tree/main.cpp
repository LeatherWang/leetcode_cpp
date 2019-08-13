
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
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

int dfs(Node* root)
{
    if(!root)
        return 0;
    int maxDepth=0;
    for(int i=0; i< root->children.size(); i++)
    {
        maxDepth = max(maxDepth, dfs(root->children[i]));
    }
    return maxDepth+1;
}

int maxDepth(Node* root)
{
    return dfs(root);
}

int main()
{
    return 0;
}









