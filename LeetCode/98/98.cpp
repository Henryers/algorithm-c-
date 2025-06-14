// 98.验证二叉搜索树

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
  bool isValidBST(TreeNode *root)
  {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
  }

  bool isValidBSTHelper(TreeNode *node, long minVal, long maxVal)
  {
    if (node == nullptr)
      return true;
    if (node->val <= minVal || node->val >= maxVal)
      return false;
    // 同理直接递归，判断左右子树是否符合条件即可，注意这里需要界定范围（上层有限制）
    return isValidBSTHelper(node->left, minVal, node->val) && isValidBSTHelper(node->right, node->val, maxVal);
  }
};