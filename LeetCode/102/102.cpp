// 102.二叉树的层序遍历

#include <iostream>
#include <algorithm>
#include <queue>

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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> res;
    if (root == nullptr)
      return res;
    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
      int count = queue.size();
      vector<int> tmp;
      while (count-- > 0)
      {
        root = queue.front();
        queue.pop();
        tmp.push_back(root->val);
        if (root->left)
          queue.push(root->left);
        if (root->right)
          queue.push(root->right);
      }
      res.push_back(tmp);
    }
    return res;
  }
};