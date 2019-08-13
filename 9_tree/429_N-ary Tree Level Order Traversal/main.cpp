
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
#include <queue>

using namespace std;
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root)
{
    vector<vector<int>> res;
    if(!root)
        return res;
    queue<Node*> myque;
    myque.push(root);
    for(;!myque.empty();)
    {
        int size = myque.size();
        vector<int> tmpVec;
        for(;size>0; size--)
        {
            Node *tmpNode = myque.front();
            myque.pop();
            tmpVec.push_back(tmpNode->val);
            for(int i=0; i<tmpNode->children.size();i++)
            {
                myque.push(tmpNode->children[i]);
            }
        }
        res.push_back(tmpVec);
    }
    return res;
}

int main()
{
    return 0;
}









