
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

void dfs(Node* root, vector<int> &res)
{
    if(!root)
        return;
    for(int i=0; i<root->children.size(); i++)
    {
        dfs(root->children[i], res);
    }
    res.push_back(root->val);
}
vector<int> postorder(Node* root)
{
    vector<int> res;
    dfs(root, res);
    return res;
}

int main()
{
    return 0;
}









