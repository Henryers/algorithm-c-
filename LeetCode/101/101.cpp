// 101.对称二叉树

#include <iostream>
#include <algorithm>
#include <queue>

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
  bool isSymmetric(TreeNode *root)
  {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
      return true;
    queue<TreeNode *> queue;
    queue.push(root->left);
    queue.push(root->right);
    while (!queue.empty())
    {
      TreeNode *left = queue.front();
      queue.pop();
      TreeNode *right = queue.front();
      queue.pop();
      if (left == nullptr && right == nullptr)
      {
        continue; // 都为空不能经过后面的push操作，但此时还没判断完不能return
      }
      else if (left == nullptr || right == nullptr)
      {
        return false; // 一个为空不对称，包false的
      }
      else if (left->val != right->val)
      {
        return false;
      }
      // 当前的left、right节点包不为空而且相等的
      // 加入的顺序都是当前层，从外往里对称加入
      //        ●
      //   ->       <-
      // ->  ->   <-  <-
      queue.push(left->left);
      queue.push(right->right);
      queue.push(left->right);
      queue.push(right->left);
    }
    return true;
  }
};