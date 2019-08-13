
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
#include <sstream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode* root)
{
    if(!root)
        return 0;
    return max(dfs(root->left), dfs(root->right))+1;
}

void dp(TreeNode* root, vector<vector<string>>& res, int depth, int start, int end)
{
    if(!root)
        return;

    res[depth][(start+end)/2] = to_string(root->val);
    if(root->left)
        dp(root->left, res, depth+1, start, (start+end)/2-1);
    if(root->right)
        dp(root->right, res, depth+1, (start+end)/2+1, end);
}

vector<vector<string>> printTree(TreeNode* root)
{
    int m = dfs(root);
    int n = pow(2, m)-1;
    vector<vector<string>> res(m, vector<string>(n, ""));
    dp(root, res, 0, 0, n-1);
    return res;
}

int main()
{
    ostringstream os;
    os<<123;
    cout<<os.str()<<endl;


    istringstream is("123");
    int a;
    is>>a;
    cout<<a<<endl;

    return 0;
}









