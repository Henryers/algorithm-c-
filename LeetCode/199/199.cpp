// 199.二叉树的右视图

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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        // 宽度优先遍历，每次取最右侧的值
        deque<TreeNode*> d;
        d.push_back(root);
        while(!d.empty()){
            int size = d.size();
            while(size--){
                // 一个个在队头弹出，左右两节点加入队列
                TreeNode* node = d.front();
                d.pop_front();
                if(node->left) d.push_back(node->left);
                if(node->right) d.push_back(node->right);
                if(size == 0) res.push_back(node->val);  // 最慢弹出的是最右侧节点
            }
        }
        return res;
    }
};