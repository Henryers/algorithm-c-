// 226.翻转二叉树

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  TreeNode *invertTree(TreeNode *root)
  {
    if (root == nullptr)
      return nullptr;
    TreeNode *tmp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = tmp;
    return root;
  }
};