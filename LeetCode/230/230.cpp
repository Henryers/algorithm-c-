// 230.二叉搜索树中第 K 小的元素

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode
{
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
  int ans = 0;
  int kthSmallest(TreeNode *root, int k)
  {
    if (root == nullptr)
      return ans;
    kthSmallest(root->left, k);
    k--;
    if (k == 0)
    {
      ans = root->val;
      return ans; // 退出递归，不需要走后续的递归
    };
    kthSmallest(root->right, k);
    return ans;
  }
};