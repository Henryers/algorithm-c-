// 94.二叉树的中序遍历

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

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
  vector<int> res;
  vector<int> inorderTraversal(TreeNode *root)
  {
    if (root == nullptr)
      return res;
    stack<TreeNode *> stk;
    while (!stk.empty() || root != nullptr)
    {
      if (root != nullptr)
      {
        // 一直遍历左边界
        stk.push(root);
        root = root->left;
      }
      else
      {
        // 左边界没了，弹栈（即最左侧的节点）
        root = stk.top();
        stk.pop(); // nm这个写法要拆开！
        res.push_back(root->val);
        root = root->right;
      }
    }
    return res;
  }
};