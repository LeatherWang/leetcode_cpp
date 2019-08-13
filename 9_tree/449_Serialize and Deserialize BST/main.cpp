
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
#include <sstream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode* root)
{
    if(!root)
        return "";
    string str = "(" + serialize(root->left) + to_string(root->val) + serialize(root->right) + ")";
    return str;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data)
{
    if(data.empty() || data.size()<=2)
        return NULL;
    TreeNode* root=NULL;
    int counter = 0;
    int n = data.size();
    for(int i=0; i<n; i++)
    {
        if(data[i] == '(')
            counter++;
        else if(data[i] == ')')
            counter--;
        else if(counter == 1)
        {
            auto pos = data.find_first_of('(',i);
            if(pos == data.npos)
            {
                root = new TreeNode(stoi(data.substr(i, data.size()-i-1)));
                root->left = deserialize(data.substr(1, i-1));
            }
            else
            {
                root = new TreeNode(stoi(data.substr(i, pos-i)));
                root->left = deserialize(data.substr(1, i-1));
                root->right = deserialize(data.substr(pos, data.size()-pos-1));
            }
            break;
        }
    }

    return root;
}


// 排名第一的算法
void coding(TreeNode* r, stringstream& ss){
    if(r == NULL){
        ss << '*';
    }
    else{
        ss << 'n' << r -> val;
        coding(r -> left, ss);
        coding(r -> right,ss);
    }
    return;
}

string serialize(TreeNode* root) {
    stringstream ss;
    coding(root, ss);
    return ss.str();
}

// Decodes your encoded data to tree.
TreeNode* decoding(stringstream& ss){
    char ch;
    ss >> ch;
    TreeNode* r = NULL;
    if(ch == '*'){
        return r;
    }
    else{
        int temp;
        ss >> temp;

        r = new TreeNode(temp);
        r -> left = decoding(ss);
        r -> right =decoding(ss);
    }
    return r;
}

TreeNode* deserialize(string data) {
    stringstream ss(data);
    TreeNode* root = decoding(ss);
    return root;
}

int main()
{
    stringstream ss;
    ss<<'n'<<23<<" "<<'2';
    int ch;
    ss>>ch;
    ss.clear();
    cout<<ss.str()<<endl;
    while(ss>>ch) cout<<ch<<endl;
    return 0;
}









