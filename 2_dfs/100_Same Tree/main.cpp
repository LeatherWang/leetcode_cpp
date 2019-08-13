
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
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q)
{
    if(p==NULL&&q==NULL)
        return true;
    else if((p==NULL&&q!=NULL)||(q==NULL&&p!=NULL))
        return false;

    if(p->val==q->val)
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    return false;
}

int main()
{
    TreeNode *mybt = new TreeNode(3);
    return 0;
}









