// 108.将有序数组转换为二叉搜索树

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
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    int l = 0;
    int r = nums.size() - 1;
    return process(nums, l, r);
  }
  TreeNode *process(vector<int> &nums, int l, int r)
  {
    if (l > r)
      return nullptr;
    int mid = (l + r) / 2;
    TreeNode *root = new TreeNode(nums[mid]); // 选中间作为根节点就好，其他交给孩子们了
    root->left = process(nums, l, mid - 1);
    root->right = process(nums, mid + 1, r);
    return root;
  }
};