// 437.路径总和 III

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int res = 0;
    int pathSum(TreeNode* root, int targetSum) {  // 本身这个函数递归不会改targetNum，不会溢出
        if (root == nullptr) return 0;
        // 当前节点为根的路径总和
        rootSum(root, targetSum);
        // 左右子树递归
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return res;
    }

    void rootSum(TreeNode* root, long targetSum){  // 得用long，不然溢出！
        if(root == nullptr) return;
        if(root->val == targetSum) {
            res++;
        }
        rootSum(root->left, targetSum - root->val);
        rootSum(root->right, targetSum - root->val);
    }
};

// 前缀和做法
// class Solution {
// public:
//     unordered_map<long, int> prefix;
    
//     int pathSum(TreeNode* root, int targetSum) {  // 本身这个函数递归不会改targetNum，不会溢出
//         prefix[0L] = 1;
//         return dfs(root, 0, targetSum);
//     }

//     int dfs(TreeNode* root, long curr, int targetSum){  // 得用long，不然溢出！
//         if(root == nullptr) return 0;
//         int res = 0;
//         curr += root->val;
//         res = prefix[curr - targetSum] ? prefix[curr - targetSum] : 0;
//         // 前缀和加上当前节点，在这颗子树下递归
//         prefix[curr] = (prefix[curr] ? prefix[curr] : 0) + 1;
//         res += dfs(root->left, curr, targetSum);
//         res += dfs(root->right, curr, targetSum);
//         // 当前路径都试过了，回溯一下
//         prefix[curr] = (prefix[curr] ? prefix[curr] : 0) - 1;
//         return res;
//     }
// };
