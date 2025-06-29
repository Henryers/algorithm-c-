// 543.二叉树的直径

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
  int res = 0;
  int diameterOfBinaryTree(TreeNode *root)
  {
    process(root);
    return res;
  }
  int process(TreeNode *root)
  {
    if (root == nullptr)
      return 0;
    int left = process(root->left);
    int right = process(root->right);
    res = max(res, left + right);
    return max(left, right) + 1;
  }
};